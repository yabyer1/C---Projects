#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "BasicShape.h"
#include <math.h>
#include <string>

class Rectangle : public BasicShape
{
    private:
        double width;
        double length;
    public:
        Rectangle(double w, double l){width = w, length = l;}
        
        void setWidth(double w){width = w, calcArea(), calcPerimeter();}
        void setLength(double l){length = l; calcArea(), calcPerimeter();}
        
        double getWidth(){return width;}
        double getLength(){return length;}
        
        void calcArea();
        void calcPerimeter();
        
};
#endif