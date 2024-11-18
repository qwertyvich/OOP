#pragma once

#include "Figure.hpp"

class Array {
public:
    Array();
    Array(const std::initializer_list<Figure*> & t);
    Array(const Array & a);
    Array(Array&& a) noexcept;
    ~Array();
    void remove(size_t idx);
    void push_back(Figure* fig);
    Figure* operator[] (int id) const;
    double get_total_area() const;
    size_t get_size() const noexcept;
    void Centers() const;
    void Areas() const;
protected:
    Figure** data;
    size_t size;
};