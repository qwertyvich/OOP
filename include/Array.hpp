#pragma once

#include "Figure.hpp"
#include <memory>

template <class T>
class Array {
public:
    Array() : size{0}, data{nullptr} {}

    Array(const std::initializer_list<T> & t) {
        size = t.size();
        data =  std::make_unique<T[]>(size);
        size_t i = 0;
        for (std::shared_ptr<T> elem : t) {
            data[i++] = elem;
        }
    }

    Array(const Array& arr) {
        size = arr.size;
        data = std::make_unique<T[]>(size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr.data[i];
        }
    }

    Array(Array&& arr) noexcept {
        data = arr.data;
        size = arr.size;
        arr.data = nullptr;
        arr.size = 0;
    }

    ~Array() {
        size = 0;
    }

    size_t get_size() const noexcept{
        return this->size;
    }

    double get_total_area() const {
        double sum = 0;
        for (size_t i = 0; i < size; ++i) {
            sum += static_cast<double>(*data[i]);
        }
        return sum;
    }

    void get_area() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << static_cast<double>(*data[i]) << std::endl;
        }
    }

    void remove(size_t idx) {
        if (idx >= size) {
            throw "out of range";
        }
        std::shared_ptr<T[]> newdata = std::make_unique<T[]>(size - 1);
        size_t j = 0;
        for (size_t i = 0; i < size - 1; ++i) {
            if (i == idx) {
                ++j;
            }
            newdata[i] = data[j];
            ++j;
        }
        --size;
        data = newdata;
    }

    void push_back(const T &fig) {
        std::shared_ptr<T[]> newdata = std::make_unique<T[]>(size + 1);
        for (size_t i = 0; i < size; ++i) {
            newdata[i] = data[i];
        }
        newdata[size] = fig;
        ++size;
        data = newdata;
    }

    T operator [] (int id) const{
        return this->data[id];
    }

    void Centers() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i]->Center() << " ";
        }
    }

    void Areas() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << (double) *data[i] << " ";
        }
    }
protected:
    std::shared_ptr<T[]> data;
    size_t size;
};