#pragma once
#include "Figure.hpp"
#include "Triangle.hpp"
#include <memory>

template <class T>
class Square : public Figure<T> {
public:
    Square(const std::initializer_list<Dot<T>> & t) : Figure<T>(t) {};
    Square() : Figure<T>{4} {};

    Dot<T> Center() const override{
        int X = 0, Y = 0;
        T res_x, res_y;

        for (size_t i = 0; i < 4; ++i) {
            X += this->dots[i].x;
            Y += this->dots[i].y;
        }

        res_x = (T)X / 4;
        res_y = (T)Y / 4;

        return {res_x, res_y};
    };

    operator double () const override{

        double area = 0;
        area = this->dots[0].x * this->dots[1].y + 
           this->dots[1].x * this->dots[2].y + 
           this->dots[2].x * this->dots[3].y + 
           this->dots[3].x * this->dots[0].y -
           (this->dots[0].y * this->dots[1].x + 
            this->dots[1].y * this->dots[2].x + 
            this->dots[2].y * this->dots[3].x + 
            this->dots[3].y * this->dots[0].x);
        area = std::abs(area) / 2.0;
        return area;
        };

    ~Square() {};
};