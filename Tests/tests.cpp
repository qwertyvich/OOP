// Tests/tests.cpp
#include <gtest/gtest.h>
#include <fstream>
#include <set>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include "../include/NPC.hpp"
#include "../include/Menu.hpp"
#include "../include/Visitor.hpp"
#include "../include/DeathHandler.hpp"

std::mutex cout_mutex;


TEST(NPCGenerationTest, NPCsWithinMapBounds) {
    std::vector<INPC*> npcArray;
    size_t npcCount = 50;
    NPCGenerator(npcArray, npcCount);
    for (const auto& npc : npcArray) {
        auto cords = npc->getCords();
        EXPECT_GE(cords.first, 0.0);
        EXPECT_LT(cords.first, 100.0) << "NPC X координата должна быть меньше 100.";
        EXPECT_GE(cords.second, 0.0);
        EXPECT_LT(cords.second, 100.0) << "NPC Y координата должна быть меньше 100.";
    }
    
    for (auto npc : npcArray) {
        delete npc;
    }
}

TEST(FightSystemTest, BattleResultsInDeath) {
    INPC* bear = new Bear(10.0, 10.0);
    INPC* elf = new Elf(15.0, 15.0);

    std::vector<INPC*> npcArray = {bear, elf};

    makeFight(npcArray);

    EXPECT_TRUE(npcArray.size() <= 2) << "После боя количество NPC не должно увеличиваться.";

    if (npcArray.size() == 1) {
        std::string remaining = npcArray[0]->getName();
        EXPECT_TRUE(remaining == "Bear" || remaining == "Elf") << "Оставшийся NPC должен быть Bear или Elf.";
    } else if (npcArray.size() == 0) {
        SUCCEED();
    } else {
        FAIL() << "Никто не умер в бою, хотя должен был.";
    }

    for (auto npc : npcArray) {
        delete npc;
    }
}

TEST(FightSystemTest, DeadNPCsDoNotParticipateInFight) {
    INPC* bear = new Bear(10.0, 10.0);
    INPC* elf = new Elf(15.0, 15.0);

    std::vector<INPC*> npcArray = {bear, elf};

    makeFight(npcArray);

    size_t size_after_first_fight = npcArray.size();

    makeFight(npcArray);

    EXPECT_EQ(npcArray.size(), size_after_first_fight) << "Размер массива должен остаться неизменным после второго боя.";

    for (auto npc : npcArray) {
        delete npc;
    }
}

TEST(SaveLoadTest, SaveAndLoadNPCs) {
    std::vector<INPC*> npcArray;
    size_t npcCount = 10;
    NPCGenerator(npcArray, npcCount);

    std::string filename = "test_npc.txt";
    saveNpcArrayToFile(npcArray, filename);

    std::vector<INPC*> loadedArray = loadNpcArrayFromFile(filename);

    EXPECT_EQ(npcArray.size(), loadedArray.size()) << "Количество NPC после загрузки должно совпадать с исходным.";

    for (size_t i = 0; i < npcArray.size(); ++i) {
        EXPECT_EQ(npcArray[i]->getName(), loadedArray[i]->getName()) << "Имена NPC должны совпадать.";
        EXPECT_EQ(npcArray[i]->getCords(), loadedArray[i]->getCords()) << "Координаты NPC должны совпадать.";
    }

    for (auto npc : npcArray) {
        delete npc;
    }
    for (auto npc : loadedArray) {
        delete npc;
    }

    std::remove(filename.c_str());
}

TEST(ThreadSafetyTest, ConcurrentOutput) {
    std::atomic<int> counter(0);
    auto print_func = [&counter, &cout_mutex]() {
        for(int i = 0; i < 100; ++i) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << "Thread " << std::this_thread::get_id() << " Count: " << counter++ << std::endl;
        }
    };

    std::thread t1(print_func);
    std::thread t2(print_func);
    std::thread t3(print_func);

    t1.join();
    t2.join();
    t3.join();

    EXPECT_EQ(counter, 300) << "Счетчик должен быть равен 300 после трех потоков по 100 итераций.";
}

TEST(FightSystemTest, DeadNPCsAreRemoved) {
    INPC* bear = new Bear(10.0, 10.0);
    INPC* elf = new Elf(15.0, 15.0); 
    INPC* outlaw = new Outlaw(80.0, 80.0);

    std::vector<INPC*> npcArray = {bear, elf, outlaw};

    makeFight(npcArray);

    EXPECT_TRUE(npcArray.size() == 2) << "Должен погибнуть один из двух NPC в бою.";

    bool outlaw_present = false;
    for (const auto& npc : npcArray) {
        if (npc->getName() == "Outlaw") {
            outlaw_present = true;
            break;
        }
    }
    EXPECT_TRUE(outlaw_present) << "Outlaw не должен участвовать в бою и должен оставаться в массиве.";

    for (auto npc : npcArray) {
        delete npc;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
