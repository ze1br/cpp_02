#include "Fixed.hpp"
#include <iostream>


Fixed::Fixed(void) : value(0) 
{
    std::cout << "Default constructor called " << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called"<<std::endl;
    if (this != &other) 
    {
        this->value = other.getRawBits();
        std::cout<<"Copy assignment operator called--->  "<<this->value<< std::endl;
    }
    return *this;
}

    Fixed::~Fixed() 
    {
    std::cout << "Destructor called " << std::endl;
    }
    int	Fixed::getRawBits( void ) const
    {
        std::cout << "getRawBIts member function called" << std::endl;
        return (this->value);
    }
    
    void	Fixed::setRawBits(int raw)
    {
        std::cout << "setRawBIts member function called" << std::endl;
        this->value = raw;
    }
     