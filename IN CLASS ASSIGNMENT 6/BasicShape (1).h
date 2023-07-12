#ifndef BASICSHAPE_H
#define BASICSHAPE_H
#include <iostream>
#include <math.h>
#include <string>

class BasicShape
{
    protected:
        double area;
        double perimeter;
    public:
        double getArea(){return area;}
        virtual void calcArea() = 0;
        double getPerimeter(){return perimeter;}
        virtual void calcPerimeter() = 0;
};
#endif