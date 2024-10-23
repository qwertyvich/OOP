#pragma once
#include <iostream>
#include <cstring>


class Octal
{
public:
    Octal();                                              // Конструктор по умолчанию
    size_t getSize() const;
    unsigned char *getNumber() const;

    Octal(const size_t &n, unsigned char t = 0);          // Конструктор заполнения
    Octal(const std::initializer_list<unsigned char> &t); // Конструктор инициализатора списка
    Octal(const std::string t);                           // Конструктор из строки
    Octal(const Octal &other);                             // Конструктор копирования
    Octal(Octal &&other) noexcept;                         // Конструктор перемещения

    std::ostream &print(std::ostream &os);

    Octal& operator=(Octal&& other) noexcept;                   // Оператор присваивания (перемещения)
    Octal operator+(const Octal &other) const;             // Оператор сложения (+)
    Octal operator-(const Octal &other) const;             // Оператор вычитания (-)
    Octal operator*(const Octal &other) const;             // Оператор умножения (*)
    bool operator==(const Octal &other) const;            // Оператор равенства (==)
    bool operator!=(const Octal &other) const;            // Оператор неравенства (!=)
    bool operator<(const Octal &other) const;             // Оператор меньше (<)
    bool operator<=(const Octal &other) const;            // Оператор меньше или равно (<=)
    bool operator>(const Octal &other) const;              // Оператор больше (>)
    bool operator>=(const Octal &other) const;             // Оператор больше или равно (>=)

    ~Octal() noexcept; //        Деструктор
private:
    size_t size;
    unsigned char *number;
};


bool isOctalDigit(const char &c);   //  проверка на восьмеричную цфифру
