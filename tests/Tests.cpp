#include <gtest/gtest.h>
#include "../include/NPC.h"
#include "../include/NPCFabric.h"
#include "../include/UI.h"
#include "../include/Visitor.h"
#include "../include/DeathAgregator.h"
#include "../include/ObserverFileOutput.h"
#include "../include/ObserverConsolOutput.h"

TEST(NPCFactoryTest, CreateBearCorrectly) {
    BearFabric bearFabric;
    INPC *bear = bearFabric.createNPC(100.0, 200.0);
    
    EXPECT_EQ(bear->getName(), "Bear");
    EXPECT_EQ(bear->getCords(), std::make_pair(100.0, 200.0));

    delete bear;
}

TEST(NPCFactoryTest, CreateElfCorrectly) {
    ElfFabric elfFabric;
    INPC *elf = elfFabric.createNPC(300.0, 400.0);
    
    EXPECT_EQ(elf->getName(), "Elf");
    EXPECT_EQ(elf->getCords(), std::make_pair(300.0, 400.0));

    delete elf;
}

TEST(NPCFactoryTest, CreateOutlawCorrectly) {
    OutlawFabric outlawFabric;
    INPC *outlaw = outlawFabric.createNPC(50.0, 100.0);
    
    EXPECT_EQ(outlaw->getName(), "Outlaw");
    EXPECT_EQ(outlaw->getCords(), std::make_pair(50.0, 100.0));

    delete outlaw;
}

TEST(NPCFightTest, BearKillsElf) {
    Bear bear(0.0, 0.0);
    Elf elf(1.0, 1.0);
    BearVisitor bearVisitor;

    bool result = elf.accept(bearVisitor);  
    EXPECT_TRUE(result); 

    EXPECT_EQ(elf.getState(), ALIVE);
}

TEST(NPCFightTest, ElfKillsOutlaw) {
    Elf elf(0.0, 0.0);
    Outlaw outlaw(1.0, 1.0);
    ElfVisitor elfVisitor;

    bool result = outlaw.accept(elfVisitor);  
    EXPECT_TRUE(result);  

    EXPECT_EQ(outlaw.getState(), ALIVE);
}


TEST(FileIOTest, SaveAndLoadNPCs) {
    std::vector<INPC*> npcArray;
    npcArray.push_back(new Bear(10.0, 20.0));
    npcArray.push_back(new Elf(30.0, 40.0));

    const std::string filename = "../npc_test.txt";

    saveNpcArrayToFile(npcArray, filename);

    std::vector<INPC*> loadedArray = loadNpcArrayFromFile(filename);

    EXPECT_EQ(loadedArray.size(), 2);
    EXPECT_EQ(loadedArray[0]->getName(), "Bear");
    EXPECT_EQ(loadedArray[0]->getCords(), std::make_pair(10.0, 20.0));
    EXPECT_EQ(loadedArray[1]->getName(), "Elf");
    EXPECT_EQ(loadedArray[1]->getCords(), std::make_pair(30.0, 40.0));

    for (auto npc : npcArray) {
        delete npc;
    }
    for (auto npc : loadedArray) {
        delete npc;
    }

    std::remove(filename.c_str());
}

TEST(NPCFactoryTest, InvalidNPCName) {
    try {
        INPC *npc = npcFromName("Dragon", 100.0, 200.0);
        FAIL() << "Expected std::logic_error";
    } catch (const std::logic_error& e) {
        EXPECT_EQ(e.what(), std::string("Неправильное имя NPC"));
    } catch (...) {
        FAIL() << "Expected std::logic_error";
    }
}

TEST(NPCTest, IsCloseTest) {
    Bear bear(0.0, 0.0);
    Elf elf(3.0, 4.0); 

   
    EXPECT_TRUE(bear.isClose(&elf, 10.0));


    EXPECT_FALSE(bear.isClose(&elf, 4.0));
}
