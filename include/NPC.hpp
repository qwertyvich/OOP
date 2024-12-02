#pragma once
#include <iostream>
#include <cmath>
#include "Visitor.hpp"

class IVisitor;

#define ALIVE 1
#define DIE 0

class INPC {
protected:
    std::string npcName;
    std::pair<double, double> cords;

public:
    explicit INPC(std::string name);
    virtual bool accept(IVisitor & visitor) = 0;
    std::string getName() const;
    std::pair<double, double> getCords() const;
    void setCords(double x, double y);
    bool isClose(INPC *obj, double dist) const;
    virtual ~INPC() = default;
    int step = 5;
    int killDist = 10;

};

class Bear : public INPC {
public:
    Bear() = delete;
    Bear(double x, double y);
    bool accept(IVisitor & visitor) override;
    int step = 5;
    int killDist = 10;

};

class Elf : public INPC {
public:
    Elf() = delete;
    Elf(double x, double y);
    bool accept(IVisitor & visitor) override;
    int step = 10;
    int killDist = 50;

};

class Outlaw : public INPC {
public:
    Outlaw() = delete;
    Outlaw(double  x, double y);
    bool accept(IVisitor & visitor) override;
    const int step = 10;
    const int killDist = 10;

};


