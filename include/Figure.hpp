#pragma once
#include <iostream>
#include <memory>
#include <cmath>

const double EPS = 1e-7;

template <class T>
struct Dot {
    T x;
    T y;
    bool operator==(Dot const& other){
        return (std::fabs(this->x - other.x) < EPS && 
                std::fabs(this->y - other.y) < EPS);
    }
};

template <class T>
class Figure {
protected:
    int num_dots = 0;
    std::shared_ptr<Dot<T>[]> dots;
    public:
    bool operator==(Figure<T> const& other) {
        if (this->num_dots != other.num_dots) {
            return false;
        }
        for(int i = 0; i < num_dots; ++i) {
            if (!(this->dots[i] == other.dots[i])) {
                std::cout << this->dots[i] << other.dots[i] <<std::endl;
                return false;
            }
        }
        return true;
    }

     
    Figure() : num_dots(0), dots(nullptr) {};

     
    Figure(int x) : num_dots(x) {
        this->dots = std::make_unique<Dot<T>[]>(num_dots);
    };

     
    Figure(const std::initializer_list<Dot<T>> & t) {
        this->num_dots = t.size();
        this->dots = std::make_unique<Dot<T>[]>(num_dots);
        int i = 0;
        for (auto elem : t) {
            dots[i++] = elem;
        }
    };

     
    Figure(const Figure<T>& other) {
        this->num_dots = other.num_dots;
        this->dots =  std::make_unique<Dot<T>[]>(num_dots);
        for(int i = 0; i < num_dots; ++i) {
            this->dots[i] = other.dots[i];
        }
    };

     
    Figure(Figure<T>&& other) {
        this->num_dots = other.num_dots;
        this->dots = other.dots;

        other.num_dots = 0;
        other.dots = nullptr;
    };

     
    void  operator=(Figure<T> const& other) {
        this->num_dots = other.num_dots;
        this->dots = std::make_unique<Dot<T>[]>(num_dots);
        for(int i = 0; i < num_dots; ++i) {
            this->dots[i] = other.dots[i];
        }
    }

     
    void  operator=(Figure<T>&& other) {
        std::cout << "MOVE\n";
        this->num_dots = other.num_dots;
        this->dots = other.dots;

        other.num_dots = 0;
        other.dots = nullptr;
    }

     
    ~Figure() {
        num_dots = 0;
    };

    virtual Dot<T> Center() const = 0;

     
    virtual operator double() const {
        std::cout << "default double\n";
        return 0.0;
    }; 

     
    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& obj) {
        for (int i = 0; i < obj.num_dots; ++i) {
            os << obj.dots[i].x << " " << obj.dots[i].y;
            os << std::endl;
        }
        return os;
    };

     
    friend std::istream& operator>>(std::istream& is, const Figure<T>& obj) {
        int x, y;
        for (size_t i = 0; i < obj.num_dots; ++i) {
            is >> obj.dots[i].x >> obj.dots[i].y;
        }
        return is;
    }

     
    friend std::ostream& operator<<(std::ostream& os, const Dot<T>& obj) {
        os << obj.x << ' ' << obj.y << std::endl;
        return os;
    };
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Dot<T>& obj) {
    os << obj.x << ' ' << obj.y << std::endl;
    return os;
}

