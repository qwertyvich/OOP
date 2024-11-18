#include "Trapezoid.hpp"
#include <cmath>

Trapezoid::Trapezoid() : Figure(4) {};

Trapezoid::Trapezoid(Dot* d) : Figure(4) {
    this->dots[0] = d[0];
    this->dots[1] = d[1];
    this->dots[2] = d[2];
    this->dots[3] = d[3];
}

Trapezoid::~Trapezoid() {};

Dot Trapezoid::Center() const{
    double x1 = dots[0].x, y1 = dots[0].y;
    double x2 = dots[1].x, y2 = dots[1].y;
    double x3 = dots[2].x, y3 = dots[2].y;
    double x4 = dots[3].x, y4 = dots[3].y;

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (denominator == 0) {
        throw std::runtime_error("Диагонали параллельны, невозможно вычислить центр.");
    }

    double numerator_x = (x1 * y2 - y1 * x2) * (x3 - x4) - (x3 * y4 - y3 * x4) * (x1 - x2);
    double numerator_y = (x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2);

    double x = numerator_x / denominator;
    double y = numerator_y / denominator;

    Dot ans;
    ans.x=x;
    ans.y = y;
    return  ans; 

}

Trapezoid::operator double() {
    double S;
    double a = std::sqrt(std::pow(dots[1].x-dots[0].x,2)+std::pow(dots[1].y-dots[0].y,2));
    double b = std::sqrt(std::pow(dots[3].x-dots[2].x,2)+std::pow(dots[3].y-dots[2].y,2));
    double height = std::abs(dots[0].y - dots[2].y);
    S = (a + b) * height / 2.0;
    return S;
};

    