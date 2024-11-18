#include "Array.hpp"

Array::Array() : size{0}, data{nullptr} {}

Array::Array(const std::initializer_list<Figure*> & t) {
    size = t.size();
    data = new Figure*[size];
    size_t i = 0;
    for (Figure* elem : t) {
        data[i++] = elem;
    }
}

Array::Array(const Array& arr) {
    size = arr.size;
    data = new Figure*[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = arr.data[i];
    }
}

Array::Array(Array&& arr) noexcept {
    data = arr.data;
    size = arr.size;
    arr.data = nullptr;
    arr.size = 0;
}

Array::~Array() {
    delete[] data;
    size = 0;
}

size_t Array::get_size() const noexcept{
    return this->size;
}

double Array::get_total_area() const {
    double sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += (double) *data[i];
    }
    return sum;
}

void Array::remove(size_t idx) {
    if (idx >= size) {
        throw "out of range";
    }
    Figure** newdata = new Figure*[size - 1];
    size_t j = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        if (i == idx) {
            ++j;
        }
        newdata[i] = data[j];
        ++j;
    }
    --size;
    delete[] data;
    data = newdata;
}

void Array::push_back(Figure* fig) {
    Figure** newdata = new Figure*[size + 1];
    for (size_t i = 0; i < size; ++i) {
        newdata[i] = data[i];
    }
    newdata[size] = fig;
    ++size;
    delete[] data;
    data = newdata;
}

Figure* Array::operator [] (int id) const{
    return this->data[id];
}

void Array::Centers() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i]->Center() << " ";
    }
}

void Array::Areas() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << (double) *data[i] << " ";
    }
}