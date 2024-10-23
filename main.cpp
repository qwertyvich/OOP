#include "includes/Octal.hpp"

int main() {
    Octal num1 = Octal("123");
    Octal num2 = Octal("456");
    
    Octal sum = num1 + num2;
    Octal diff = num2 - num1;
    Octal product = num1 * num2;
    
    std::cout << "Num1: ";
    num1.print(std::cout);
    
    std::cout << "Num2: ";
    num2.print(std::cout);
    
    std::cout << "Sum: ";
    sum.print(std::cout);
    
    std::cout << "Difference: ";
    diff.print(std::cout);
    
    std::cout << "Product: ";
    product.print(std::cout);
    
    return 0;
}
