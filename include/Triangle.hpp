#pragma once
#include "Figure.hpp"
#include <memory>

template <class T>
class Triangle : public Figure<T> {
private:

public:
    Triangle(const std::initializer_list<Dot<T>> & t) : Figure<T>(t) {};
    Triangle() : Figure<T>(3) {};
    Triangle(Dot<T> *d) : Figure<T>(3) {
    this->dots[0] = d[0];
    this->dots[1] = d[1];
    this->dots[2] = d[2];
    };
    ~Triangle() {};
    Dot<T> Center() const override{
        int X = 0, Y = 0;
        T res_x, res_y;

        for (size_t i = 0; i < 3; ++i) {
            X += this->dots[i].x;
            Y += this->dots[i].y;
        }

        res_x = (T)X / 3;
        res_y = (T)Y / 3;

        return {res_x, res_y};
    };
    operator double () const override{
        double S;
        S = 0.5 * std::fabs((this->dots[1].x - this->dots[0].x) * (this->dots[2].y - this->dots[0].y) \
        - (this->dots[2].x - this->dots[0].x) * (this->dots[1].y - this->dots[0].y));
        return S;
    };
};