#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <set>
#include "NPCFabric.h"
#include "UI.h"
#include "DeathAgregator.h"

#define WIGHT 500
#define HIGH 500
#define BearType 1
#define ElfType 2
#define OutlawType 3

void NPCGenerator(std::vector<INPC*> &npcArray, size_t npcCount);

void saveNpcArrayToFile(const std::vector<INPC*> &npcArray, const std::string &filename);

INPC *npcFromName(const std::string &name, double x, double y);

std::vector<INPC*> loadNpcArrayFromFile(const std::string &filename);

void makeFight(std::vector<INPC*> &npcArray);





