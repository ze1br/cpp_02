#include <iostream>

class counter {
private:
    int count;

public:
    int value;
    static const int	fxd = 8;
     counter();                      // Default
     counter(counter& other);  // Copy constructor
     
    // Destructor declaration
    ~counter();

    // Accessor methods
    int getRawBits(void)const;
    void setRawBits(int raw);
    counter& operator=(const counter& other);
};
 
counter::counter(void) : count(0) 
{
    std::cout << "Default constructor called (count = 0)" << std::endl;
}
counter::counter(counter& other)
{
    *this = other;
}

 counter::~counter() 
{
    std::cout << "Destructor called " << std::endl;
}
int	counter::getRawBits( void ) const
{
	std::cout << "getRawBIts member function called" << std::endl;
	return (this->count);
}

void	counter::setRawBits(int raw)
{
	std::cout << "setRawBIts member function called" << std::endl;
	this->value = raw;
}
 
counter& counter::operator=(const counter& other)
{
    if (this != &other)
     {
        count = other.count;
        value = other.getRawBits();
        std::cout << "Copy assignment operator called " << std::endl;
    }
    return *this;
}
int main( void ) 
{
    counter a;
    counter b( a );
    counter c;
       c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
