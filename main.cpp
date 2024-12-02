#include "include/FightHandler.hpp"

std::mutex mutex;

void printMap(std::vector<INPC*> & npcArray) {
    mutex.lock();
    for (int i = 0; i < HIGH; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            bool check = false;
            for (auto & elem : npcArray) {
                if (elem->getCords().first == j && elem->getCords().second == i) {
                    if (elem->getName() == "Bear") {
                        std::cout << 'B';
                        check = true;
                    } else if (elem->getName() == "Elf") {
                        std::cout << 'E';
                        check = true;
                    } else if (elem->getName() == "Outlaw") {
                        std::cout << 'O';
                        check = true;
                    }
                }
            }
            if (!check) {
                std::cout << ' ';
            }
        }
        std::cout <<  std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;
    mutex.unlock();
}

int main() {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration;
    std::vector<INPC*> npcArray;
    const int npcCount = 50;
    NPCGenerator(npcArray, npcCount);
    std::thread thread([&]() {
        start = std::chrono::steady_clock::now();
        while (true) {
            srand(time(nullptr));
            while (true) {
                mutex.lock();
                for (auto & elem : npcArray) {
                    int stepSide = rand() % 4;
                    double x = elem->getCords().first;
                    double y = elem->getCords().second;
                    switch (stepSide) {
                        case (UP) : {
                            if (y + elem->step < HIGH) {
                                elem->setCords(x, y + elem->step);
                            }
                            break;
                        }
                        case (DOWN) : {
                            if (y - elem->step >= 0) {
                                elem->setCords(x, y - elem->step);
                            }
                            break;
                        }
                        case (LEFT) : {
                            if (x - elem->step >= 0) {
                                elem->setCords(x - elem->step, y);
                            }
                            break;
                        }
                        case (RIGHT) : {
                            if (elem->step + x < WIDTH) {
                                elem->setCords(x + elem->step, y);
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
                mutex.unlock();
                std::thread fightThread([&]() {
                    std::set<INPC *> deadNote;

                    DeathHandler deathAgregator;
                    ObserverFileOutput fileObserver;
                    deathAgregator.attach(&fileObserver);

                    BearVisitor bearVisitor;
                    ElfVisitor elfVisitor;
                    OutlawVisitor outlawVisitor;
                    mutex.lock();
                    for (const auto &attacker: npcArray) {
                        for (const auto &defender: npcArray) {
                            if (attacker != defender && attacker->isClose(defender, attacker->killDist)) {
                                int attackerCapacity = 1 + rand() % 6;
                                int defenderCapacity = 1 + rand() % 6;
                                bool fightStatus;
                                if (attacker->getName() == "Bear") {
                                    fightStatus = defender->accept(bearVisitor);
                                } else if (attacker->getName() == "Elf") {
                                    fightStatus = defender->accept(elfVisitor);
                                } else {
                                    fightStatus = defender->accept(outlawVisitor);
                                }
                                if (fightStatus && attackerCapacity > defenderCapacity) {
                                    deadNote.insert(defender);
                                }
                            }
                        }
                    }

                    for (const auto &death: deadNote) {
                        deathAgregator.notify(death);
                    }
                    std::vector<INPC*> newNpcArray;
                    for (auto it = npcArray.begin(); it != npcArray.end(); ++it) {
                        if (!deadNote.count(*it)) {
                            newNpcArray.push_back(*it);
                        }
                    }
                    npcArray = newNpcArray;
                    mutex.unlock();

                    deathAgregator.detach(&fileObserver);
                    return;
                });

                fightThread.join();
                end = std::chrono::steady_clock::now();
                duration = end - start;
                if (duration.count() >= 30) {
                    return;
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::chrono::time_point<std::chrono::steady_clock> mainStart = std::chrono::steady_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> mainEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> mainDuration;

    while (true) {
        printMap(npcArray);
        mainEnd = std::chrono::steady_clock::now();
        mainDuration = mainEnd - mainStart;
        if (mainDuration.count() >= 30) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    thread.join();

    return 0;

}