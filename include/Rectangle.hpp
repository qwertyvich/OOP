#pragma once

#include "Figure.hpp"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const std::initializer_list<Dot> & t) : Figure(t) {};
    ~Rectangle();
    Dot Center() const override;
    operator double() override;
};