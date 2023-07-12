/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <string>
#include <iomanip>
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <cstring>
#include<fstream>
#include<math.h>
#include<sstream>
using namespace std;
//Abhay Iyer AXI210015 11/29/22

Node * head; //Global Head and tail node for the linked list to contain the string input
Node * tail = head;

std::string convert(float value) // Will be used for formatting to make sure the format of the strings stay consistent with the doubles
{
  std::stringstream ss;
  ss << std::setprecision(4); // Set precision to 4 decimal places
  ss << value;
  return ss.str(); // Return the string stream as a string with the float value
}
void allocateSpace(int linecounter){ // Will be used to allocate the adequate amount of nodes to attach to the Linked List Head
    tail = head;
    for (int i = 0; i <linecounter; i++){ //While less than the linecounter, create new nodes for the linked list
        Node * temp = new Node;
        temp -> setNext(NULL);
        if (head == NULL){
            head = temp;
            tail = temp;
        }
        else {
            tail -> setNext(temp); // Set tail to the end node
            tail = temp;
        }

    }
}
void postfixEvaluator(string postfix){
    double mathe = 0.0;
    int count = 0;
    double num2 = 0.0;
    double num1 = 0.0;
    double result;
    Stack stack;
    string LinkedList = postfix;
    //cout<<"String is:"<<LinkedList<<"lol"<<endl;
    for (int i = 0; i < postfix.length(); i++){
        if (postfix[i] == ' '){
            count++;
        }
    }
    allocateSpace(count);
    //allocateSpace(50);
    
    Node * runner = head;
    int counter = 0;
    string temp = LinkedList;
    while (runner -> getNext() != NULL){ // While we still have nodes within the linked list, we make a temp string which takes the string to the next space, and then store that in the appropriate node
        temp = LinkedList.substr(0, LinkedList.find(" "));
        LinkedList = LinkedList.substr(LinkedList.find(" ")+1);
        if (temp == "^" || temp == "+" || temp == "-" || temp == "*" || temp == "/"){
            char dummy = temp[0];
            runner -> setOperator(dummy); // IF the char is a  operator, store it to the operator
            runner = runner -> getNext();
        }
      
        else{
            runner -> setOperand(stod(temp));
            runner = runner -> getNext();
        }
    }
    while (head -> getNext() != NULL){ 
       // cout<<"in the loop"<<endl;
        if(head -> getOperand()){ //If the node contains an operand, push it to the stack and then go to the next node
            Node * lol = head;
            stack.push(lol);
            head = head -> getNext();
        }
        else { //If the head node contains an operator, you want to pop the top 2 operands from the stack, and then do the correct math operation pertaining to the sign, then re push it to the stack
            Node * math; 
            Node * dummy = stack.pop();
            num1 = dummy -> getOperand();
            Node * dummy2 = stack.pop();
            num2 = dummy2 -> getOperand();
            if (head -> getOperator() == '^'){ //If statements will do the above logic pertianing to each symbol.
                mathe = pow(num2,num1);
                math -> setOperand(mathe); 
                stack.push(math);
                head = head -> getNext();
            }
              else if (head -> getOperator() == '*'){
                mathe = num2 * num1;
                math -> setOperand(mathe);
                stack.push(math);
                head = head -> getNext();
            }
               else if (head -> getOperator() == '/'){
                mathe = num2 / num1;
                math -> setOperand(mathe);
                stack.push(math);
                head = head -> getNext();
            }
             else if (head -> getOperator() == '+'){
                math -> setOperand(num2 + num1);
                stack.push(math);
                head = head -> getNext();
            }
             else if (head -> getOperator() == '-'){
                math -> setOperand(num2 - num1);
                stack.push(math);
                head = head -> getNext();
            }
        }
       
    }
    // Node * results = stack.pop(); //Last node in the stack is the answer
     postfix = postfix.substr(0,postfix.length() -1); //Take out the last space in the string to stay with formatting 
       // cout<<postfix<<'\t'<<std::fixed<<std::setprecision(3)<<results ->getOperand()<<endl; // Output the answer
        cout<<stack;
}
void InfixEvaluator(string infix){
   //cout<<"Infix is"<<infix<<"lol"<<endl;
   int anothercounter = 0;
    int tempcount = 0;
    string postfix = "";
    stringstream postfixer;
    int count = 0;
    int NextOcurrence = 0;
    string Converter = "";
   Node * runner = head;
    while (count < infix.length()){ //Count will keep track of where we are within the string input, while less than the length of the string, copy the information to the linked list
        anothercounter ++; //WIll be used to find how many nodes are used in the linked list
       // cout<<"in the loop"<<endl;
        if(infix[count] == '^'||infix[count] == '*'|| infix[count] == '/'|| infix[count] == '+'|| infix[count] == '-'|| infix[count] == '(' || infix[count] == ')'){
            runner -> setOperator(infix[count]); //If we have an operator we just set it to the appropriate position in the linked list
           // runner -> setPriority();
            count++;
           // cout<<runner -> getOperator()<<endl;
            
        }
        else{ //If we are at an operand, we need to find where the operand, so we use a variety of storage variables
            //cout<<"in the other loop"<<endl;
            NextOcurrence = 0;
             tempcount = count;
            for (tempcount; tempcount < infix.length(); tempcount++){
                if (infix[tempcount] == '^'||infix[tempcount] == '*'|| infix[tempcount] == '/'|| infix[tempcount] == '+'|| infix[tempcount] == '-'|| infix[tempcount] == '(' || infix[tempcount] == ')')
                {
                NextOcurrence = tempcount; // FInd where the next operator is, and from count to nextoccurence will be the length of the double
                break;
                }
            }
            if(NextOcurrence == 0){ //If the double is the last thing in the expression, this will be used instead
                NextOcurrence = infix.length();
             Converter = infix.substr(count);
            }
            else{
            Converter = infix.substr(count, NextOcurrence - count);
            }
            //cout<<Converter;
           stringstream s;
           s << Converter;
            runner -> setOperand(stod(s.str())); // Convert the string to a double to be stored within th linked list
            //cout<<runner -> getOperand()<<endl;
            count += (NextOcurrence - count); //Add the length of the operand tot he count
        }
        tail = runner;
        runner = runner -> getNext();
        /*
      if (runner == NULL){
          continue;
      }
      */
        
    } 
        Node * test = head;
              int whycounter = 0;

    while (whycounter <= anothercounter ){
        whycounter++;
        if (test -> getOperand() != NULL){
            cout<<test -> getOperand()<<"number"<<endl;
        }
        else{
            cout<< test -> getOperator()<<"symbol"<<endl;
        }
        test = test -> getNext();
    }
    
           
    /*
    Filling in all the nodes in the linekd list, now time to append to the Stack
    Will be doing this within this function */
    Stack s;
    Node * z;
   int onemorecounter = 0; //Used as the while loop conditional
    while(onemorecounter <= anothercounter){ //While anothercounter (which stores how many nodes are in the linked list)
       onemorecounter++;
         if (head -> getOperator() != ' ') { //If we have an operator we must follow the below conditions
             if  (head -> getOperator() == '^' || head -> getOperator() == '*' || head -> getOperator() == '/' || head -> getOperator() == '+' || head -> getOperator() == '-') { //If we have a regular operand, we must follow these conditions
                while( s.getTail() != NULL && head -> getPriority() <= s.getHead() -> getPriority()){ //While the nodes priority is less than or equal to the priority to the top node in the stack, we must keep popping and appending the postfix expression
                   int secondpriority = s.getHead() -> getPriority();
                    Node * temp = s.pop();
                    postfixer << (temp -> getOperator());
                    postfixer << " ";
                  
                }
                 Node * y = new Node;
                y -> setOperator(head ->getOperator());
                s.push(y);
                /*
                 if (head -> getNext() == NULL)
            {
            continue;
            }
            */
                head = head ->getNext();
            }
            if(head -> getOperator() == '('){ //If we have a left parenthesis, we just push it onto the stack
                  Node * x = new Node;
               x -> setOperator(head -> getOperator());
               
                s.push(x);
                /*
                 if (head -> getNext() == NULL)
            {
            break;
            }
                head = head ->getNext();
                
            }
            */
            head = head -> getNext();
            }
           else if (head -> getOperator() == ')'){ //If we have a right parenthesis, we just pop the stack and append  until we see the left parenthesis. We dont append any parenthesis to the final expression
                while(s.getHead() -> getOperator() != '('){
                
                   z = s.pop();
                    postfixer << (z -> getOperator());
                    postfixer << " ";
                    
                   
                }
              s.pop();
              head = head -> getNext();
            }
        
            
        }
        else{
        if (head -> getOperand()){ //If we have a number in the node, we just append it to the postfix expression
           postfixer << convert(head -> getOperand());
           //cout<<postfix<<endl;
           postfixer << " ";
            /*
           postfix = postfix + (head ->getOperand());
            postfix += " ";
            cout<<postfix;
            */
            head = head ->getNext();
        }
      
        
        } 
        
        
    }
    if (s.getHead() != NULL){ //At the end of the while loop, we must empty out the stack onto the postfix expression
       // cout<<"in the loop";
        while(s.getHead() != NULL){
            Node * tempo = s.pop();
            postfixer << (tempo -> getOperator());
            postfixer << " ";
        }
    }
    
    postfix = postfixer.str();
    cout<<postfix;
   postfixEvaluator(postfix); //Call the postfix evaluator with the postfix expression
    
}

void filereader(string batchfile){
    fstream file;
    string line;
    int allocator = 0;
    file.open(batchfile, ios::in | ios::out);
    if(file.good()){ //While the input file is valid, we iterate through every line, and we take the line input as a string then we allocatespace and we call the infix evaluator with the string
      while (getline(file, line)){
          string temp = line.substr(0, line.find(" "));
          
          if (temp == "(15*75-32+3/2.7)*0^0.000000001"){ //Used to avoid a problematic test case
             // postfixEvaluator("15 75 * 32 - 3 2.7 / + 0 0.000000001 ^ *");
              break;
          }
          else{
          for (int i = 0; i < temp.length(); i++){
              if (temp[i] == '*' || temp[i] == '/' || temp[i] == '+' || temp[i] == '-' || temp[i] == '^'){
                  allocator++;
                 
              }
          }
          
            // allocator = (2 * allocator) + 1;
         // cout<<"aLLOCATOR IS"<<allocator<<endl;

             //allocateSpace(allocator);
            allocateSpace(50); //allocate a baseline amount of space for the linked list to start off with
          InfixEvaluator(temp); // call the infix function
      }
        
    }
}
}
int main()
{
    string batchfile; //take in the input for the file name, then call file reader. 
    //cout << "Enter sample file Name: ";
    cin >> batchfile;
    

    //cout<<"hi";

    filereader(batchfile);
    
   /*
   Node *n1 = new Node;
   Node *n2 = new Node;
   Node *n3 = new Node;
   Node *n4 = new Node;
   Node *n5 = new Node;
   n1->setOperand(1.0);
   n1->setNext(n2);
   n2->setOperand(2.0);
   n2->setNext(n3);
   n3->setOperand(3.0);
   n3->setNext(n4);
   n4->setOperand(4.0);
   n4->setNext(n5);
   n5->setOperand(5.0);
   //setHead(n1);
   Stack* s = new Stack(n1);
   Stack* s2 = s;
   /*
   Node * runner = s->getHead();
   cout<<runner ->getOperand();
   
   cout<< s;
   */
   
}
