#include "../include/Menu.hpp"

void NPCGenerator(std::vector<INPC*> &npcArray, size_t npcCount) {
    srand(time(nullptr));
    for (size_t i = 0; i < npcCount; ++i) {
        INPC *npc = nullptr;
        int randomNumber = std::rand() % NPC_CNT + 1;
        double x = std::rand() % WIDTH;
        double y = std::rand() % HIGH;
        switch (randomNumber) {
            case BearType:
                {
                    BearFabric bearFabric;
                    npc = bearFabric.createNPC(x, y);
                }
                break;
            case ElfType:
                {
                    ElfFabric elfFabric;
                    npc = elfFabric.createNPC(x, y);
                }
                break;
            case OutlawType:
                {
                    OutlawFabric outlawFabric;
                    npc = outlawFabric.createNPC(x, y);
                }
            default:
                break;
        }
        npcArray.emplace_back(npc);
    }
}

void saveNpcArrayToFile(const std::vector<INPC*> &npcArray, const std::string &filename) {
    std::ofstream file(filename);
    try {
        if (!file.is_open()) {
            throw std::logic_error("Ошибка открытия файла");
        } else {
            for (auto & npc : npcArray) {
                file << npc->getName() << ' ' << npc->getCords().first << ' ' << npc->getCords().second << std::endl;
            }
        }
        file.close();
    } catch (std::exception & ex) {
        std::cout << ex.what() << std::endl;
    }
}

INPC *npcFromName(const std::string &name, double x, double y) {
    if (name == "Bear") {
        BearFabric bearFabric;
        return bearFabric.createNPC(x, y);
    } else if (name == "Elf") {
        ElfFabric elfFabric;
        return elfFabric.createNPC(x, y);
    } else if (name == "Outlaw") {
        OutlawFabric outlawFabric;
        return outlawFabric.createNPC(x, y);
    } else {
        throw std::logic_error("Неправильное имя NPC");
    }
}

std::vector<INPC*> loadNpcArrayFromFile(const std::string &filename) {
    std::vector<INPC*> npcArray;
    std::ifstream file(filename);
    try {
        if (!file.is_open()) {
            throw std::logic_error("Ошибка открытия файла");
        } else {
            std::string npcName;
            double x, y;
            while (file >> npcName >> x >> y) {
                npcArray.emplace_back(npcFromName(npcName, x, y));
            }
            file.close();
        }
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    return npcArray;
}

void makeFight(std::vector<INPC*> &npcArray) {
    std::set<INPC*> deadNote;

    DeathHandler deathAgregator;
    ObserverFileOutput fileObserver;
    ObserverConsolOutput consolObserver;
    deathAgregator.attach(&fileObserver);
    deathAgregator.attach(&consolObserver);

    BearVisitor bearVisitor;
    ElfVisitor elfVisitor;
    OutlawVisitor outlawVisitor;

    for (const auto & attacker : npcArray) {
        for (const auto & defender : npcArray) {
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

    for (const auto & death : deadNote) {
        deathAgregator.notify(death);
    }
    for (auto it = npcArray.begin(); it != npcArray.end(); ++it) {
        if (deadNote.count(*it)) {
            npcArray.erase(it);
        }
    }

    deathAgregator.detach(&consolObserver);
    deathAgregator.detach(&fileObserver);
}

