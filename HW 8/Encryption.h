#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include "FileFilter.h"
#include <iostream>
#include <string>
//Abhay Iyer AXI210015
class Encryption : public FileFilter
{
private:
int key;

public:
Encryption(){key = 5;}
Encryption(int val){key = val;}
void SetKey(int val){key = val;}
void doFilter(ifstream &in, ofstream &out, int x);
};
#endif