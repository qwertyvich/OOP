#pragma once
#include <iostream>
#include <cmath>
#include "Visitor.h"

class IVisitor;

#define ALIVE 1
#define DIE 0

class INPC {
protected:
    std::string npcName;
    bool state;
    std::pair<double, double> cords;
public:
    explicit INPC(std::string name);
    virtual bool accept(IVisitor & visitor) = 0;
    bool getState() const;
    std::string getName() const;
    std::pair<double, double> getCords() const;
    bool isClose(INPC *obj, double dist) const;
    virtual ~INPC() = default;
};

class Bear : public INPC {
public:
    Bear() = delete;
    Bear(double x, double y);
    bool accept(IVisitor & visitor) override;
};

class Elf : public INPC {
public:
    Elf() = delete;
    Elf(double x, double y);
    bool accept(IVisitor & visitor) override;

};

class Outlaw : public INPC {
public:
    Outlaw() = delete;
    Outlaw(double  x, double y);
    bool accept(IVisitor & visitor) override;

};


