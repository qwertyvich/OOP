#include "../include/DeathAgregator.h"



void DeathAgregator::attach(IObserver *observer) {
    observers.push_back(observer);
}


void DeathAgregator::detach(IObserver *observer) {
    int n = static_cast<int>(observers.size());
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if(observers[i] == observer) {
            index = i;
        }
    }
    if (index != -1) {
        std::swap(observers[n - 1], observers[index]);
    }
    observers.resize(n - 1);
}


void DeathAgregator::notify(INPC( *npc)) {
    for (auto & observer : observers) {
        observer->update(npc);
    }
}
