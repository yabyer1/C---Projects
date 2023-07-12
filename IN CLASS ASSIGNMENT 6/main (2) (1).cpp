/******************************************************************************
Matthew Chen MNC160430
Abhay Iyer AXI210015
Abhay did circle.h and circle.cpp, Matthew did rectangle.h and rectangle.cpp
and we both worked on basicshape.h and main together
*******************************************************************************/
#include <iostream>
#include <math.h>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <string>
using namespace std;
void output(BasicShape* p)
{
    p -> calcArea();
    p -> calcPerimeter();
    cout << p -> getArea() << endl;
    cout << p -> getPerimeter() << endl;
}

int main()
{
    Circle* basic = new Circle(0,0,5);
    output(basic);
    Rectangle* basic1 = new Rectangle(5,5);
    output(basic1);
    return 0;
}