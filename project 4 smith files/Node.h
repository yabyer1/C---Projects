#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
//Abhay Iyer AXI210015
class Node
{
private:
double operand; //Used to store the number value for each node
char symbol; //Used to store the operator value for each node
Node * next = NULL; //Used to get the pointer to the enxt node
int priority; //Used to store the priority to the operator value
public:

 Node(); //Constructors
 Node(const Node &x);
 Node(double);
 Node(char);
 Node* getNext(){return next;} //Getters
double getOperand(){return operand;}
char getOperator(){return symbol;}
int getPriority() {return priority;}
void setOperand(double o); //Setters
void setOperator(char s);
void setPriority();
void setNext(Node * ptr);
bool isEmpty(); //Will check if a Node is empty
      
};
#endif
