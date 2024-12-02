#pragma once
#include "Observer.hpp"


class ObserverConsolOutput : public IObserver {
public:
    void update(INPC *npc) const noexcept override;
};



