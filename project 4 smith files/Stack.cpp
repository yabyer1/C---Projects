//Abhay Iyer AXI210015
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include "Stack.h"
    Stack::Stack(Node *ptr){
        Node * x = new Node;
        x = ptr;
        head = x;
        tail = x;
    }
    Stack::Stack(const Stack &x){
       head = x.head;
       tail = x.tail;
        /*
        Node* runner1 = j -> head;
        Node * runner2 = x -> head;
        while(runner2 != NULL){
            runner1 = runner2;
            runner1 = runner1 -> next;
            runner2 = runner2 -> next;
        }
        tail = runner1;
        */
    }
Node* Stack::getHead(){
    return head;
} 
Node* Stack::getTail(){
    return tail;
}
/*
void Stack::SetHead(Node* x){
    head = x;
}
void Stack::SetTail(Node* y){
    tail = y;
}
*/
/*
std::ostream &operator<<( std::ostream &s, const Stack& x){
    Node * runner =  x.head;
    while(runner != NULL){
        if(runner -> getOperator() != ' '){
            if (runner -> getNext() == NULL){
               s << runner ->getOperator();
            }
            else
            s<<runner -> getOperator()<<", ";
        }
       else{
            if (runner -> getNext() == NULL){
                s << runner ->getOperand();
            }
            else
          s<<runner -> getOperand()<<", ";
        }
        runner = runner -> getNext();
    }
    return s;
}
*/
std::ostream &operator<<(std::ostream &os, Stack const &stack){
    Node* ptr = stack.head;
   
        //loop through every node
    while(ptr){
        //check datatype to print
        if(ptr->getOperand() != -1){ //if there is a number, print the number
            //convert number to string to print every digit
            std::stringstream ss; //create string stream
            ss << std::fixed << std::setprecision(9) << ptr->getOperand(); //put the number into the string stream
            std::string s = ss.str(); //convert string stream to string
            size_t point = s.find('.');
            if(s.find('.') != std::string::npos){
               while (s[s.size() - 1] == '0' || s[s.size() - 1] == '.'){ //delete trailing zeroes
                  if(s[s.size() - 1] == '.'){
                    s = s.substr(0, s.size()-1);
                    break;
                  }
                  s = s.substr(0, s.size()-1); 
               }
            }

            os << s; //append it to the output stream
            ss.str(std::string()); //reset the string stream
        }else {
            os << ptr->getOperator();
        }
        ptr = ptr->getNext();
        if(ptr){
           os << " ";
        }
    }
    return os;
}
/*
void Stack::operator<<( Node* &x){ 
    Node *  y = x;
        y -> setNext(head);
        head = y;
        if (tail == NULL)
        tail = head;
}
*/
void Stack::operator<< (Node * &x) //PUSHING ONTO STACK
{
    Node * copy = new Node;

    if(x->getOperator() == ' ')
    {
        copy->setOperand(x->getOperand());
    }
    else
    {
        copy->setOperator(x->getOperator());
    }

    copy->setNext(head);
    head = copy;
  
}
Node* Stack::operator>>( Node* &x){ //POPPING OFF OF THE STACK
    x = head;
    if (head == tail){
    tail = tail -> getNext();

   }
    head = head -> getNext();
    x -> setNext(NULL);
    return x;
}
void Stack::push(Node* &x){ //Pushing onto the stack
     Node * copy = new Node;
     
    if(x->getOperator() == ' ')
    {
        copy->setOperand(x->getOperand());
    }
    else
    {
        copy->setOperator(x->getOperator());
    }

    copy->setNext(head);
    head = copy;
    if (tail == NULL){
        tail = head;
    }
   
    
}

Node* Stack::pop(){ //Popping off the stack
      Node *x = head;
      
    if (head == tail){
     tail = NULL;
     head = NULL;
   }
   
   else{
    head = head -> getNext();
   }
   
  
   x -> setNext(NULL);
    return x;
}
void Stack::Destructor(Node * &head){ //Recursive delete function to delete all the nodes off
    if(head == NULL){
        return;
    }
    Node * dummy = head -> getNext();
    delete head;
    Destructor(dummy);
}


//}