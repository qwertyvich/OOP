#pragma once
#include "Observer.hpp"
#include <fstream>



class ObserverFileOutput : public IObserver {
public:
    void update(INPC *npc) const noexcept override;
};

