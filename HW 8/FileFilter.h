#ifndef FILEFILTER_H
#define FILEFILTER_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Abhay Iyer AXI210015
class FileFilter
{
public:
virtual void doFilter(ifstream &in, ofstream &out){};

};
#endif