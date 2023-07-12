#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "BasicShape.h"
#include <math.h>
#include <string>

class Circle : public BasicShape
{
    private:
        double centerX;
        double centerY;
        double radius;
    public:
        Circle(double x, double y, double r){centerX = x, centerY = y, radius = r;}
        void setCenterX(double x){centerX = x;}
        void setCenterY(double y){centerY = y;}
        void setRadius(double r){radius = r;}
        
        double getCenterX(){return centerX;}
        double getCenterY(){return centerY;}
        double getRadius(){return radius;}
        
        void calcArea();
        void calcPerimeter();
        
};
#endif