#pragma once
#include "NPC.h"

class INPC;

class IObserver {
public:
    virtual void update(INPC *npc) const noexcept = 0;
};

