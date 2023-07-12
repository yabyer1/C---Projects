//Abhay Iyer AXI210015
#include "Encryption.h"
    void Encryption :: doFilter(ifstream &in, ofstream &out, int linenumber){
       int high = 127;
       int low = 31;
        int count = 0;
         string line;
        while (in.good()){
        getline(in,line);
        count++;
        for (int i = 0; i < line.length(); i++){
            line[i] = line[i] + key;
            
            if (line[i] > 126){
                int firstdif = line[i] - high;
            line[i] = firstdif + 32;
                 
            }
            if (line[i] < 32){
                int seconddif = line[i] - low;
                line[i] = seconddif + 126;
                 
            }
            out<<line[i];
        }
        if(count < linenumber)
        out<<'\n';
        }
        
      
        }
    
    