#pragma once
#include "Figure.hpp"

class Trapezoid : public Figure {


public:
    Trapezoid();
    Trapezoid(Dot* d);
    Trapezoid(const std::initializer_list<Dot> & t) : Figure(t) {};
    ~Trapezoid();
    Dot Center() const override;
    operator double() override;
};