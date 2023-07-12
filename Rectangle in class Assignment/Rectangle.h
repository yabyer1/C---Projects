/**************************

Update STACK class:
- overloaded >> operator for popping
- overloaded << operator for pushing
- overloaded << operator for printing stack
**************************/

// header guard
#ifndef RECTANGLE_H
#define RECTANGLE_H

// libraries
#include <string>

class Rectangle
{
private: // member variables
    double length;
    double width;

// default constructor, overloaded constructor, copy constructor, accessors/mutators
public: 
    
    // default constructor
    Rectangle() { length = 0; width = 0;}

    // overloaded constructor: makes a copy of node passed in, points head + tail at new node
    Rectangle(double l, double w) { length = l; width = w;}
    

    // copy constructor that accepts a Rectangle object
    Rectangle(const Rectangle&); 
    
    // accessors
    double getLength() {return length;}
    double getWidth() {return width;}
    
    // mutators 
    void setLength(double l) { length = l;}
    void setWidth(double w) { width = w; } 

    // overloaded operators
    // (1) addition operator
    Rectangle operator+(Rectangle right);
    
    // (1) subtraction operator
    Rectangle operator-(Rectangle right);
    
    // prefix
    Rectangle& operator++();

    // postfix
    Rectangle operator++(int);

    // less than
    friend bool operator<(const Rectangle &left, const Rectangle &right );

    // greater
    friend bool operator>(const Rectangle &left, const Rectangle &right);
    
    // insertion / printing
    friend std::ostream& operator<<(std::ostream& os, const Rectangle &s);
    


    
 

};

    

#endif