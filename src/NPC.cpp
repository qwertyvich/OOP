#include "../include/NPC.h"


INPC::INPC(std::string name) : npcName(std::move(name)), state(ALIVE) {}

bool INPC::isClose(INPC *obj, double dist) const{
    std::pair<double, double> cordAttacker = this->getCords();
    std::pair<double, double> cordDefender = obj->getCords();
    double x = cordAttacker.first - cordDefender.first;
    double y = cordAttacker.second - cordDefender.second;
    double distance = std::sqrt(x * x + y * y);
    return dist >= distance;
}

bool INPC::getState() const { return state; }


std::string INPC::getName() const { return npcName; }


std::pair<double, double> INPC::getCords() const { return cords; }


Bear::Bear(double x, double y) : INPC("Bear") {
    cords = std::make_pair(x, y);
    std::cout << "Создан Медведь\n";
    std::cout << "С кординатами: " << "( " << x << ", " << y << " )\n";
}

bool Bear::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}




Elf::Elf(double x, double y) : INPC("Elf") {
    cords = std::make_pair(x, y);
    std::cout << "Создан Эльф\n";
    std::cout << "С кординатами: " << "( " << x << ", " << y << " )\n";
}

bool Elf::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}




Outlaw::Outlaw(double x, double y) : INPC("Outlaw") {
    cords = std::make_pair(x, y);
    std::cout << "Создан Разбойник\n";
    std::cout << "С кординатами: " << "( " << x << ", " << y << " )\n";
}

bool Outlaw::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}

