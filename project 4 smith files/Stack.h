//Abhay Iyer AXI210015
#ifndef STACK_H
# define STACK_H
#include <iostream>
#include <ostream>
#include "Node.h"
class Stack
{
private:
Node * head; //Contain a head value to check the top of stack
Node * tail; //Will point to the bottom of the stack

public:
 Stack(){ head = NULL;  tail = NULL;} //Constructors
 Stack(const Stack &x);
 Stack(Node* ptr);
 Node* getHead(); //Getters
Node* getTail();
void setHead(Node* x){head = x;} //Setters
void setTail(Node* y){tail = y;}
friend std::ostream& operator<<(std::ostream& s, const Stack& x); //Operators overloading
Node* operator>>( Node* &x);
void operator<<( Node* &x);
Node* pop();
void push(Node* &x);
void Destructor(Node * &head);// Recursive Destructor function
~Stack() {Destructor(head); } //Destructor function that is calling the recursive destructor function
};

#endif
