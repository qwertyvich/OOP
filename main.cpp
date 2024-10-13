//Лаб 1. Вариант 18. Проверка слова на палиндром
#include <iostream>
#include <cstring>
#include "include/palindrom.h"

#define N 1000

using namespace std;

int main(int argc, char *argv[])
{
    char string1[N];
    std::cin.getline(string1, N);

    if (palindrom(string1))
    {
        std::cout << "The word is not a palindrome" << endl;
    }
    else{
        std::cout << "The word is a palindrome" << endl;
    }

    return 0;
}