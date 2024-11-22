#pragma once

#include "Figure.hpp"
#include "Triangle.hpp"
#include <memory>

template <class T>
class Rectangle : public Figure<T> {
public:
    Rectangle(const std::initializer_list<Dot<T>> & t) : Figure<T>(t) {};
    Rectangle() : Figure<T>(4) {};
    ~Rectangle() {};
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
    operator double () const override {
        Dot<T> d[] = {this->dots[0], this->dots[1], this->dots[2]};
        Triangle<T> t1(d);
        Dot<T> d2[] = {this->dots[1], this->dots[2], this->dots[3]};
        Triangle<T> t2(d2);

        double s;
        s = (double)t1 + (double)t2;

        return s;
        

    
    };
};