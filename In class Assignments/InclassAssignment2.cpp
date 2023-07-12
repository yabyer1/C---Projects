/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Abhay Iyer (AXI210015) 
//Andrew Avery (ARA200003)
#include <memory>
#include <iostream>
#include<fstream>
#include <string>
#include <cstdio>

#include <iomanip>

using namespace std;

/*int sum(shared_ptr<int[]> ptr,int size){
    for (int i = 1; i =< size; i++)
    
}*/

int main()
{
    
   fstream file;
   string line;
   file.open("Random.txt", ios::in|ios::out);
   int count = 0;
   if(file){
      
   while(getline(file,line)){
       
       //cout<<line<<endl;
       for(int x=0;x<line.length();x++){
         if(isdigit(line.at(x))){
             continue;
         }
         else{
             count++;
         }
           }
       /*for(int i = 0; i <line.length(); i++){
           if(line.at(i) ==' '){
               count++;
           }
       }*/
       count++;
   }
   
   }
    file.clear();
    file.close();
   
   shared_ptr<int[]> ptr(new int[count]) ;
   int placement = 0;
   file.open("Random.txt", ios::in| ios::out);
    string temp;
    int i = 0;
    while(!file.eof()){
        file >> temp;
        //cout << temp << endl;
        *(ptr.get() + i) = stoi(temp);
        i++;
    }
  int sum = 0;
  float average = 0;
  int highest = *(ptr.get());
  int lowest = *(ptr.get());
  for (int i = 0; i < 100; i++){
      sum += *(ptr.get() + i);
      if (*(ptr.get() + i) < lowest){
          lowest = *(ptr.get() + i);
      }
       if (*(ptr.get() + i) > highest){
          highest = *(ptr.get() + i);
      }
      
  }
  average = sum / count;
  
  cout<<"Sum is "<<sum<<endl;
  cout<<"Average is "<<average<<endl;
  cout<<"Highest is "<<highest<<endl;
  cout<<"Lowest is "<<lowest<<endl;
}
   

