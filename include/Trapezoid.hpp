#pragma once
#include "Figure.hpp"
#include <memory>

template <class T>
class Trapezoid : public Figure<T> {

public:
Trapezoid(const std::initializer_list<Dot<T>> & t) : Figure<T>(t) {};
    Trapezoid() : Figure<T>(4) {};
    Trapezoid(Dot<T> *d) : Figure<T>(4) {
    this->dots[0] = d[0];
    this->dots[1] = d[1];
    this->dots[2] = d[2];
    this->dots[3] = d[3];
    };
    ~Trapezoid() {};
    Dot<T> Center() const override
    {
        double x1 = this->dots[0].x, y1 = this->dots[0].y;
        double x2 = this->dots[1].x, y2 = this->dots[1].y;
        double x3 = this->dots[2].x, y3 = this->dots[2].y;
        double x4 = this->dots[3].x, y4 = this->dots[3].y;

        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (denominator == 0) {
            throw std::runtime_error("Диагонали параллельны, невозможно вычислить центр.");
        }

        double numerator_x = (x1 * y2 - y1 * x2) * (x3 - x4) - (x3 * y4 - y3 * x4) * (x1 - x2);
        double numerator_y = (x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2);

        T x = (T)numerator_x / denominator;
        T y = (T)numerator_y / denominator;

        Dot<T> ans;
        ans.x=x;
        ans.y = y;
        return ans; 
    };
    operator double () const override{
        double S;
        double a = std::sqrt(std::pow(this->dots[1].x-this->dots[0].x,2)+std::pow(this->dots[1].y-this->dots[0].y,2));
        double b = std::sqrt(std::pow(this->dots[3].x-this->dots[2].x,2)+std::pow(this->dots[3].y-this->dots[2].y,2));
        double height = std::abs(this->dots[0].y - this->dots[2].y);
        S = (a + b) * height / 2.0;
        return S;
    };
};