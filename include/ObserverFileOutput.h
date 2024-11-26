#pragma once
#include "Observer.h"
#include <fstream>

class ObserverFileOutput : public IObserver {
public:
    void update(INPC *npc) const noexcept override;
};

