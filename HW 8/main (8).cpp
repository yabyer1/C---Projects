/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*Create a driver program that tests each class.
Prompt the user for the file to read
This file will be used for all tests
Use an Encryption object with the default key value
call the doFilter function
write the resulting file to EncryptionDefault.txt
Use an Encryption object with a  key value of 12
call the doFilter function
write the resulting file to Encryption12.txt
Use an Encryption object with a key value of -4
call the doFilter function
write the resulting file to Encryption-4.txt
Use an Uppercase object
call the doFilter function
write the resulting file to Uppercase.txt
Use a Copy object
call the doFilter function
write the resulting file to Copy.txt
*/
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include "FileFilter.h"
#include "Encryption.h"
#include "Uppercase.h"
#include "Copy.h"
using namespace std;

int main()
{
    int linenumber = 0;
    string line;
    string filename;
    string firstcase = "EncryptionDefault.txt";
    string badcount = "Encryption12.txt";
    string secondcase = "Encryption-4.txt";
    string thirdcase = "Uppercase.txt";
    string fourthcase = "Copy.txt";
    ofstream firstof; 
    ofstream secondof; 
    ofstream thirdof; 
    ofstream fourthof; 
    ofstream badof;
    firstof.open(firstcase);
    secondof.open(secondcase);
    thirdof.open(thirdcase);
    fourthof.open(fourthcase);
    badof.open(badcount);
    cout<<"File Name: ";
    cin>> filename;
    fstream linecounter;
    linecounter.open(filename);
    while(getline(linecounter, line)){
        linenumber++;
    }
    //cout<<linenumber;
    ifstream lol;
    lol.open(filename);
    Encryption x;
    x.doFilter(lol, firstof, linenumber);
      ifstream second;
    second.open(filename);
    Encryption y(12);
   y.doFilter(second, badof, linenumber);
     ifstream third;
    third.open(filename);
    Encryption z(-4);
  z.doFilter(third, secondof, linenumber);
    ifstream fourth;
    fourth.open(filename);
    Uppercase a;
   a.doFilter(fourth, thirdof, linenumber);
     ifstream fifth;
    fifth.open(filename);
    Copy w;
   w.doFilter(fifth, fourthof, linenumber);
   lol.clear();
/*
       string filename,outfile;
    cout<<"Enter File Name: ";
    cin>>filename;

    ofstream outFile;
    ifstream inFile;
    inFile.open(filename);

    if(inFile==NULL)
    {
        cout<<"Cannot open the file "<<filename;
        exit(0);
    }

    Encryption e;
    UpperCase c;
    Copy c2;

    do{
    cout<<"1.Encryption"<<endl;
    cout<<"2.To transform uppercase"<<endl;
    cout<<"3.Copy to another file"<<endl;
    cout<<"4.exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    int key;
    switch(choice)
    {
    case 1:
        cout<<"Enter Encryption Key(2-25): ";
        cin>>key;
        cout<<"Enter output file name: ";
        cin>>outfile;
        outFile.open(outfile);
        
        if(outFile==NULL)
        {
        cout<<"Cannot create the file "<<filename;
        exit(0);
        }

        e=Encryption(key);
        e.doFilter(inFile,outFile);
        cout<<"File Encrypted Successfully"<<endl;
        break;
    case 2:
        cout<<"Enter output file name: ";
        cin>>outfile;
        outFile.open(outfile);
        
        if(outFile==NULL)
        {
        cout<<"Cannot create the file "<<filename;
        exit(0);
        }

        
        c.doFilter(inFile,outFile);
        cout<<"File Transformed Successfully"<<endl;
        break;

    case 3:
        cout<<"Enter output file name: ";
        cin>>outfile;
        outFile.open(outfile);
        
        if(outFile==NULL)
        {
        cout<<"Cannot create the file "<<filename;
        exit(0);
        }

        
        c2.doFilter(inFile,outFile);
        cout<<"File Copied Successfully"<<endl;
        break;
    case 4:
        exit(0);
    default:
        cout<<"Invalid choice"<<endl;
    }
    }while(1);
    system("pause");
    */
    return 0;
}
