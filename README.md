# Лабораторная работа №1

ТЕМА: ПЕРВАЯ ПРОГРАММА НА C++ 

Цель:

+ Изучить систему сборки CMake
+ Изучить базовые операторы и конструкции C++
+ Изучить библиотеку для написания Unit-тестов Google Test
+ Научится писать простые программы, использующие ввод/вывод через потоки std::cin
std::cout

> Вариант №18. Напишите функцию, которая осуществляет проверку на палиндром строки

#### Установка
```bash
sudo apt update
git clone --branch lab1 https://github.com/qwertyvich/OOP.git
cd OOP
git clone https://github.com/google/googletest.git
mkdir build 
cd build 
cmake .. 
make run_tests 
./run_tests
```