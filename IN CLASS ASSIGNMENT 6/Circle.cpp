#include "Circle.h"

void Circle::calcArea()
{
    area =  pow(radius,2) * M_PI;
}
void Circle::calcPerimeter()
{
    perimeter = 2 * M_PI * radius;
}