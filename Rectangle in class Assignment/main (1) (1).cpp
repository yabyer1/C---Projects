/******************************************************************************
postfix
- copy object
- increment original
- return copy

Emilie Grace Baillo
eeb220002

Abhay Iyer
AXI210015

*******************************************************************************/
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    Rectangle r1(10, 10);
    Rectangle r2 = r1;
    
    // change r1
    r1.setLength(5);
    r1.setWidth(5);
    
    cout << (r1+r2) << endl;
    cout << (r1-r2) << endl;
    cout << (++r1) << endl;
    cout << (r2++) << endl;
    cout << (r1 < r2) << endl;
    cout << (r1 > r2) << endl;
    cout << "r1 area: " << (r1.getLength()*r1.getWidth()) << endl;
    cout << "r2 area: " << (r2.getLength()*r2.getWidth()) << endl;


    
    return 0;
}
