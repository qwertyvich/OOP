#include "Square.hpp"
#include <cmath>

Square::Square() : Figure{4} {};

Dot Square::Center() const {
    double X = 0, Y = 0;

    for (size_t i = 0; i < num_dots; ++i) {
        X += dots[i].x;
        Y += dots[i].y;
    }

    double res_x = X / num_dots;
    double res_y = Y / num_dots;
    Dot ans;
    ans.x=res_x;
    ans.y = res_y;
    return  ans; 
}

Square::operator double() {
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

Square::~Square() {};