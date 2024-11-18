#include "Figure.hpp"
#include <cmath>

const double EPS = 1e-7;

bool Dot::operator==(Dot const& other) {
    return (std::fabs(this->x - other.x) < EPS && 
            std::fabs(this->y - other.y) < EPS);
}


Figure::Figure() : num_dots(0), dots(nullptr) {};

Figure::Figure(int x) : num_dots(x) {
    this->dots = (Dot*)malloc(sizeof(Dot)*num_dots);
};

Figure::Figure(const std::initializer_list<Dot> & t) {
    this->num_dots = t.size();
    this->dots = (Dot*)malloc(sizeof(Dot)*num_dots);
    int i = 0;
    for (auto elem : t) {
        dots[i++] = elem;
    }
};

Figure::Figure(const Figure& other) {
    //std::cout << "COPY\n";
    this->num_dots = other.num_dots;
    this->dots = new Dot[num_dots];
    for(int i = 0; i < num_dots; ++i) {
        this->dots[i] = other.dots[i];
    }
};

Figure::Figure(Figure&& other) {
    this->num_dots = other.num_dots;
    this->dots = other.dots;

    other.num_dots = 0;
    other.dots = nullptr;
};

void Figure::operator=(Figure const& other) {
    this->num_dots = other.num_dots;
    this->dots = new Dot[num_dots];
    for(int i = 0; i < num_dots; ++i) {
        this->dots[i] = other.dots[i];
    }
}

void Figure::operator=(Figure&& other) {
    std::cout << "MOVE\n";
    this->num_dots = other.num_dots;
    this->dots = other.dots;

    other.num_dots = 0;
    other.dots = nullptr;
}

Figure::~Figure() {
    num_dots = 0;
    free(dots);
};



Figure::operator double() {
    std::cout << "Default double" << std::endl;
    return 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& obj) {
    for (int i = 0; i < obj.num_dots; ++i) {
        os << obj.dots[i].x << " " << obj.dots[i].y;
        os << std::endl;
    }
    return os;
};

std::istream& operator>>(std::istream& is, const Figure& obj) {
    int x, y;
    for (size_t i = 0; i < obj.num_dots; ++i) {
        is >> obj.dots[i].x >> obj.dots[i].y;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Dot& obj) {
    os << obj.x << ' ' << obj.y << std::endl;
    return os;
};