#include "../include/NPCFabric.h"


INPC *BearFabric::createNPC(double x, double y) { return new Bear(x, y); }

INPC *ElfFabric::createNPC(double x, double y) { return new Elf(x, y); }

INPC *OutlawFabric::createNPC(double x, double y) { return new Outlaw(x, y); }

INPCFabric::~INPCFabric() = default;

