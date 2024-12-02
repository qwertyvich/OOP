#pragma once
#include <iostream>
#include <vector>
#include "ObserverFileOutput.hpp"
#include "ObserverConsolOutput.hpp"

class IDeathAgregator {
protected:
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify(INPC *npc) = 0;
};

class DeathHandler : public IDeathAgregator {
private:
    std::vector<IObserver*> observers;
public:
    void attach(IObserver *observer) override;
    void detach(IObserver *observer) override;
    void notify(INPC *npc) override;
};
