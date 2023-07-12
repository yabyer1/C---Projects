//Abhay Iyer AXI210015
#include "Node.h"
     Node::Node(){
        operand = 0.0;
        symbol = ' ';
       
    }
    Node::Node(double o){
        operand = o;
        symbol = ' ';
        
    }
     Node::Node(char s){
        symbol = s;
        operand = 0.0;
      //  setPriority();
    }
    Node::Node(const Node &x){
        operand = x.operand;
        symbol = x.symbol;
        (*next) = *(x.next);
       // setPriority();
    }
    /*
    double Node::getOperand(){
        return  operand;
    }
    
char Node::getSymbol(){
    return  symbol;
}
Node * Node::getNext(){
    return next;
}
*/
void  Node::setOperand(double o){
    operand = o;
}
void  Node::setOperator(char s){
     symbol = s;
      setPriority(); //If we set the operator, make an autocall to the priority to get the priority value
}
void Node::setNext(Node* ptr){
    next = ptr;
}
void Node::setPriority(){ //Set priority based off how the stack should compute the values
    if (symbol == '^'){
        priority = 3;
    }
    else if (symbol == '*'){
        priority = 2;
    }
    else if (symbol == '/'){
        priority = 2;
    }
    else if (symbol == '+'){
        priority = 1;
    }
    else if (symbol == '-'){
        priority = 1;
    }
    else if (symbol == '('){
        priority = 0;
    }

}
bool Node::isEmpty(){ //Will check if a ndoe is empty, if none of the data is initialized
    if(symbol == ' ' && operand == 0.0){
        return true;
    }
    return false;
}

    
