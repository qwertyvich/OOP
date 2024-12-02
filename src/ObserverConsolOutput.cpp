#include "../include/ObserverConsolOutput.hpp"


std::ostream & operator<< (std::ostream &out, const std::pair<double, double> & p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

void ObserverConsolOutput::update(INPC *npc) const noexcept {
    std::cout << "Убит " << npc->getName() << std::endl;
    std::cout << "С кординатами: " << npc->getCords() << std::endl;
}

