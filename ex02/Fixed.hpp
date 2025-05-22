#ifndef FIXED_HPP
#define  FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed 
{
private:

    int     fixedPointValue;
    static const int    fractionalBits = 8;

public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed& other);
    
    // Assignment operator
    Fixed& operator=(const Fixed& other);
    
    // Destructor
    ~Fixed();

    int getFixedPointValue() const;
    void setFixedPointValue(int value);
    
    // Conversion
    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
 
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();        
    Fixed operator++(int);      
    Fixed& operator--();        
    Fixed operator--(int);      

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    
};
    std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
    
    
#endif