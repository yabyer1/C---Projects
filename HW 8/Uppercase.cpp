//Abhay Iyer AXI210015
#include "Uppercase.h"
    void Uppercase :: doFilter(ifstream &in, ofstream &out, int linenumber){
      char ch; string line; int count;
      count = 0;
        if(in.good())
        {
       while (getline(in,line)){
           count ++;
        for (int i = 0; i < line.length(); i++){
           char x =  transform(line[i]);
           out<<x;
        }
        if(count < linenumber){
           // cout<<"in the loop";
            out<<'\n';
        }
       }   
    }
    }
      char Uppercase :: transform(char c){
        int x = int(c);
        if( c >= 'a' && c <= 'z'){
            x -= 32;
        }
        c = char(x);
        return c;
    }