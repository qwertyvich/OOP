#include <iostream>
#include "Array.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"

int main() {
    Square sq = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Trapezoid t = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{-2, -2}};
    

    std::cout << "Квадрат:\n" << sq;
    std::cout << "Прямоугольник:\n" << r;
    std::cout << "Трапеция:\n" << t;


    Array arr1 = {&sq, &r, &t};

    std::cout << "\nГеометрические центры фигур в массиве:\n";
    arr1.Centers();

    std::cout << "\nПлощади фигур в массиве:\n";
    arr1.Areas();

    std::cout << "\nУдаление фигуры по индексу 1\n";
    arr1.remove(1);

    std::cout << "\nГеометрические центры после удаления:\n";
    arr1.Centers();

    std::cout << "\nПлощади фигур после удаления:\n";
    arr1.Areas();

    return 0;
}
