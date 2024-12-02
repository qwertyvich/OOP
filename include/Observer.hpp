#pragma once
#include "NPC.hpp"

class INPC;

class IObserver {
public:
    virtual void update(INPC *npc) const noexcept = 0;
};

