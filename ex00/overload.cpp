
//--- Operator Overload Definitions ---//

 counter& counter::operator++()
{
    ++count;
    return *this;
}

 counter counter::operator++(int)
{
    counter temp(*this);
    count++;
    return temp;
}// Default constructor


 counter& counter::operator--()
{
    --count;
    return *this;
}

 counter counter::operator--(int) 
{
    counter temp(*this);
    count--;
    return temp;
}

 counter counter::operator+(const counter& obj) const
{
    return counter(count + obj.count);
}

 counter counter::operator-(const counter& obj) const
{
    return counter(count - obj.count);
}

 counter counter::operator-(const counter& obj) const
{
    return counter(count - obj.count);
}

counter& counter::operator=(const counter& other)
{
    if (this != &other) {
        count = other.count;
        std::cout << "Copy assignment operator called (count = " << count << ")" << std::endl;
    }
    return *this;
}

 std::ostream& operator<<(std::ostream& os, const counter& c) 
{
    os << c.get_count();  // Access count via public getter
    return os;
}