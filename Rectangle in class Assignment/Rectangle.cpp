#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(const Rectangle &r)
{
    length = r.length;
    width = r.width;
}

Rectangle Rectangle::operator+(Rectangle right)
{
    Rectangle x;
    x.length = this->length + right.length;
    x.width = this->width + right.width;
    return x;
}


Rectangle Rectangle::operator-(Rectangle right)
{
    Rectangle x;
    x.length = this->length - right.length;
    x.width = this->width - right.width;
    
    if(x.length <0)
    {
        x.length = 0;
    }
    
    if(x.width <0)
    {
        x.width = 0;
    }
    
    return x;
}

// prefix 
Rectangle& Rectangle::operator++()  
{
    length++;
    width++;
    return *this;
}

// postfix 
Rectangle Rectangle::operator++(int x)  
{
    Rectangle temp = *this;
    this->width++;
    this->length++;

    return temp;
}

// greater than
bool operator>(const Rectangle &left, const Rectangle &right)
{
    if((left.length)*(left.width) > (right.length)*(right.width))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// less than
bool operator<(const Rectangle &left, const Rectangle &right)
{
    if((left.length)*(left.width) < (right.length)*(right.width))
    {
        return true;
    }
    else
    {
        return false;
    }
}


std::ostream& operator<<(std::ostream& os, const Rectangle &s)
{
    os << "length: " << s.length << std::endl;
    os << "width: " << s.width << std::endl;    
    return os;
}




