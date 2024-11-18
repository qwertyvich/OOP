#pragma once
#include <iostream>

struct Dot {
    double x;
    double y;
    bool operator==(Dot const& other);
};

class Figure {
protected:
    int num_dots = 0;
    Dot* dots;
public:
    Figure();
    Figure(int x);
    Figure(const std::initializer_list<Dot> & t);
    Figure(const Figure& other);
    Figure(Figure&& other);
    virtual Dot Center() const = 0;
    void operator=(Figure const& other);
    void operator=(Figure&& other);
    ~Figure();
    virtual operator double();
    friend std::ostream& operator<<(std::ostream& os, const Figure& obj);
    friend std::istream& operator>>(std::istream& is, const Figure& obj);
};

std::ostream& operator<<(std::ostream& os, const Dot& obj);

