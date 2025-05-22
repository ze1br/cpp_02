#include <iostream>
#include <cmath>  // For roundf function

class Fixed 
{
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8; // Number of fractional bits

public:
    // Constructors
    Fixed();
    Fixed(int intValue);
    Fixed(float floatValue);
    
    // Copy constructor and assignment operator
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    // Getter and Setter
    int getFixedPointValue() const;
    void setFixedPointValue(int value);

    float toFloat() const;
    int toInt() const; 
    //    std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int intValue) : _fixedPointValue(intValue << _fractionalBits) 
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float floatValue) : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Getter and Setter for _fixedPointValue
int Fixed::getFixedPointValue() const {
    return _fixedPointValue;
}

void Fixed::setFixedPointValue(int value) {
    _fixedPointValue = value;
}

// Convert fixed-point value to a floating-point number
float Fixed::toFloat() const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); 
}

// Convert fixed-point value to an integer
int Fixed::toInt() const 
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int main() {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "a multipl is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // Using getter and setter
    std::cout << "a getFixedPointValue: " << a.getFixedPointValue() << std::endl;
    a.setFixedPointValue(9999);
    std::cout << "a setFixedPointValue: " << a.getFixedPointValue() << std::endl;

    return 0;
}






// #include <iostream>
// #include <cmath>  // For roundf function

// class Fixed 
// {

// private:
 
//     int _fixedPointValue;
//     static const int _fractionalBits = 8; // Number of fractional bits

// public:
//     // Constructors
//     Fixed();
//     Fixed(int intValue);
//     Fixed(float floatValue);
    
//     // Copy constructor and assignment operator
//     Fixed(const Fixed &other);
//     Fixed& operator=(const Fixed &other);

    
//     ~Fixed();

//      float toFloat() const;
//     int toInt() const;

//      friend std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
// };

// #include "Fixed.hpp"

// // Default constructor
// Fixed::Fixed() : _fixedPointValue(0) {
//     std::cout << "Default constructor called" << std::endl;
// }

// Fixed::Fixed(int intValue) : _fixedPointValue(intValue << _fractionalBits) 
// {
//     std::cout << "Int constructor called" << std::endl;
// }

//  // 1 << _fractionalBits = 256; 
// Fixed::Fixed(float floatValue) : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits)))
// {
//     std::cout << "Float constructor called" << std::endl;
// }

//  Fixed::Fixed(const Fixed &other) {
//     std::cout << "Copy constructor called" << std::endl;
//     *this = other;
// }

//  Fixed& Fixed::operator=(const Fixed &other)
//  {
//     std::cout << "Copy assignment operator called" << std::endl;
//     if (this != &other) 
//     {
//         _fixedPointValue = other._fixedPointValue;
//     }
//     return *this;
// }

//  Fixed::~Fixed() 
// {
//     std::cout << "Destructor called" << std::endl;
// }

// // Convert fixed-point value to a floating-point number
// float Fixed::toFloat() const
// {
//     return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); 
// }

// // Convert fixed-point value to an integer
// int Fixed::toInt() const 
// {
//     return _fixedPointValue >> _fractionalBits;
// }

//  std::ostream& operator<<(std::ostream &out, const Fixed &fixed) 
// {
//     out << fixed.toFloat();
//     return out;
// }


// int main() {
//     Fixed a;
//     Fixed const b(10);
//     Fixed const c(42.42f);
//     Fixed const d(b);
    
//     a = Fixed(1234.4321f);

//     std::cout << "a is " << a << std::endl;
//     std::cout << "a multipl is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
    
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;

//     return 0;
// }
