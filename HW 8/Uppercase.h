#ifndef UPPERCASE_H
#define UPPERCASE_H
#include "FileFilter.h"
#include <iostream>
#include <string>
//Abhay Iyer AXI210015
class Uppercase : public FileFilter
{

public:
char transform(char ch);
void doFilter(ifstream &in, ofstream &out, int linenumber);
};
#endif