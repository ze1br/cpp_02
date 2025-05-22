#include    <iostream>
#include    <cmath>   
#include    "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(int intValue) : fixedPointValue(intValue << fractionalBits) {}

Fixed::Fixed(float floatValue) : fixedPointValue(roundf(floatValue * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed &other) 
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout<<"i get callaed : coco _lina"<<std::endl;
    if (this != &other) 
    {
        fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

int Fixed::getFixedPointValue() const 
{
    return fixedPointValue;
}

void Fixed::setFixedPointValue(int value)
{
    fixedPointValue = value;
}

// Convert fixed-point value to a floating-point number
float Fixed::toFloat() const
{
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits); 
}

// Convert fixed-point value to an integer
int Fixed::toInt() const 
{
    return fixedPointValue >> fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const 
{
    return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return fixedPointValue != other.fixedPointValue;
}


Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

 Fixed& Fixed::operator++() 
{
    ++fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    ++fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() 
{
    --fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --fixedPointValue;
    return temp;
}

 Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
 
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
