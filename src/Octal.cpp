#include "../includes/Octal.hpp"
#include <algorithm>
#include <initializer_list>
#include <string>
#include <stdexcept>

//  проверка на восьмеричную цфифру
bool isOctalDigit(const char &c)
{
    return ('0' <= c && c <= '7');
}


Octal::Octal() : size(0), number{nullptr}
{
}


size_t Octal::getSize() const
{
    return size;
}


unsigned char *Octal::getNumber() const
{
    return number;
}


Octal::Octal(const size_t &n, unsigned char t)
{
    number = new unsigned char[n];
    for (size_t i = 0; i < n; i++)
        number[i] = t;
    size = n;
}


Octal::Octal(const std::initializer_list<unsigned char> &t)
{
    number = new unsigned char[t.size()];
    size = t.size();
    size_t i{size};
    for (unsigned char c : t)
    {
        if (!isOctalDigit(c))
        {
            throw std::logic_error("Octal digit must be between 0 and 7");
        }
        number[--i] = c;
    }
}

Octal::Octal(const std::string t)
{
    size = t.size();
    number = new unsigned char[size];
    for (size_t i = size; i-- > 0;)
    {
        if (!isOctalDigit(t[i]))
        {
            throw std::logic_error("Octal digit must be between 0 and 7");
        }
        number[size - i - 1] = t[i] - '0';
    }
}


Octal::Octal(const Octal &other)
{
    size = other.size;
    number = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
    {
        number[i] = other.number[i];
    }
}


Octal::Octal(Octal &&other) noexcept
{
    size = other.size;
    number = other.number;  

    other.size = 0;
    other.number = nullptr;
}


Octal& Octal::operator=(Octal&& other) noexcept
{
    if (this == &other) {return *this;}
    
    delete[] number;
    number = other.number;
    size = other.size;
    other.number = nullptr;
    other.size = 0;
    
    return *this; 
}


Octal Octal::operator+(const Octal &other) const
{
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++)
    {
        int d1 = (i < size) ? (number[i] - '0') : 0;
        int d2 = (i < other.size) ? (other.number[i] - '0') : 0;

        int sum = d1 + d2 + carry;
        result[i] = (sum % 8) + '0';
        carry = sum / 8;
    }
    if (carry > 0)
    {
        result[resultSize - 1] = carry + '0';
    }
    if (result[resultSize - 1] == '0')
    {
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Octal(result);
}


Octal Octal::operator-(const Octal &other) const
{
    if (*this < other)
    {
        throw std::logic_error("Difference can't be negative");
    }
    size_t resultSize = std::max(other.size, size);
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++)
    {
        int d1 = (i < size) ? (number[i] - '0') : 0;
        int d2 = (i < other.size) ? (other.number[i] - '0') : 0;

        int diff = d1 - d2 - carry;
        if (diff < 0)
        {
            diff += 8;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result[i] = diff + '0';
    }
    size_t nonZeroPos = result.find_last_not_of('0');
    if (nonZeroPos != std::string::npos)
    {
        result.erase(nonZeroPos + 1);
    }
    else
    {
        result = "0";
    }
    std::reverse(result.begin(), result.end());
    return Octal(result);
}


Octal Octal::operator*(const Octal &other) const       // умножение
{
    size_t resultSize = size + other.size; 
    std::string result(resultSize, '0');    


    for (size_t i = 0; i < size; i++)
    {
        int d1 = number[i];  
        int carry = 0; 

        for (size_t j = 0; j < other.size; j++)
        {
            int d2 = other.number[j];  
            int product = d1 * d2 + (result[i + j] - '0') + carry;  

            result[i + j] = (product % 8) + '0';  
            carry = product / 8;  
        }

        if (carry > 0)
        {
            result[i + other.size] += carry;  
        }
    }
    size_t nonZeroPos = result.find_last_not_of('0');
    if (nonZeroPos != std::string::npos)
    {
        result.erase(nonZeroPos + 1);
    }
    else
    {
        result = "0";
    }
    std::reverse(result.begin(), result.end());
    return Octal(result);
}


bool Octal::operator==(const Octal &other) const
{
    if (size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (number[i] != other.number[i])
        {
            return false;
        }
    }
    return true;
}

//                       опиратор неравенства
bool Octal::operator!=(const Octal &other) const
{
    return !(*this == other);
}


bool Octal::operator<(const Octal &other) const
{
    if (size != other.size)
    {
        return size < other.size;
    }

    for (size_t i = size; i--;)
    {
        if (number[i] != other.number[i])
        {
            return number[i] < other.number[i];
        }
    }

    return false;  // Если все элементы равны
}


bool Octal::operator<=(const Octal &other) const
{
    return (*this < other) || (*this == other);
}


bool Octal::operator>(const Octal &other) const
{
    return !(*this <= other);
}


bool Octal::operator>=(const Octal &other) const
{
    return !(*this < other);
}


std::ostream &Octal::print(std::ostream &os)
{
    for (size_t i = size; i--;)
    {
        os << static_cast<char>(number[i] + '0');
    }
    os << std::endl;
    return os;
}


Octal::~Octal() noexcept
{
    delete[] number;
}
