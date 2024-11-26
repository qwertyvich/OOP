#pragma once
#include "Observer.h"

class ObserverConsolOutput : public IObserver {
public:
    void update(INPC *npc) const noexcept override;
};



