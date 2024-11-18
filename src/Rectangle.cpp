#include "Rectangle.hpp"
#include <cmath>

Rectangle::Rectangle() : Figure(4) {};

Rectangle::~Rectangle() {};

Dot Rectangle::Center() const {
    int X = 0, Y = 0;
    double res_x, res_y;

    for (size_t i = 0; i < num_dots; ++i) {
        X += dots[i].x;
        Y += dots[i].y;
    }

    res_x = (double)X / num_dots;
    res_y = (double)Y / num_dots;
    Dot ans;
    ans.x=res_x;
    ans.y = res_y;
    return  ans; 
};

Rectangle::operator double() {
    double area = 0;
    area = dots[0].x * dots[1].y + 
           dots[1].x * dots[2].y + 
           dots[2].x * dots[3].y + 
           dots[3].x * dots[0].y -
           (dots[0].y * dots[1].x + 
            dots[1].y * dots[2].x + 
            dots[2].y * dots[3].x + 
            dots[3].y * dots[0].x);
    area = std::abs(area) / 2.0;
    return area;
};

