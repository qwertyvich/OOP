#pragma once
#include "Figure.hpp"

class Square : public Figure {
public:
    Square();
    Square(const std::initializer_list<Dot> & t) : Figure(t) {};
    Dot Center() const override;
    operator double() override;
    
    ~Square();
};