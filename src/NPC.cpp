#include "../include/NPC.hpp"

INPC::INPC(std::string name) : npcName(std::move(name)) {}

bool INPC::isClose(INPC *obj, double dist) const{
    std::pair<double, double> cordAttacker = this->getCords();
    std::pair<double, double> cordDefender = obj->getCords();
    double x = cordAttacker.first - cordDefender.first;
    double y = cordAttacker.second - cordDefender.second;
    double distance = std::sqrt(x * x + y * y);
    return dist >= distance;
}

void INPC::setCords(double x, double y) {
    this->cords = {x, y};
}

std::string INPC::getName() const { return npcName; }

std::pair<double, double> INPC::getCords() const { return cords; }

Bear::Bear(double x, double y) : INPC("Bear"), step(5), killDist(10) {
    cords = std::make_pair(x, y);
}

bool Bear::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}

Elf::Elf(double x, double y) : INPC("Elf"), step(10), killDist(50) {
    cords = std::make_pair(x, y);
}

bool Elf::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}

Outlaw::Outlaw(double x, double y) : INPC("Outlaw"), step(10), killDist(10) {
    cords = std::make_pair(x, y);
}

bool Outlaw::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}

