/**~*~*~*
CIS 22C
Project: Stack of strings

Written by: Rimma Esheva
IDE: VS Code
*~*/
#include <iostream>
#include <string>
using namespace std;

class Stack_str
{
private:
   // Structure for the stack nodes
   struct StackNode {
       string value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   //~Stack_str();                           // Destructor

   // Stack operations
   bool isEmpty() {
       if(length == 0) {
           return true;
       } else {
          return false;
       }
    }
   bool push(string);
   // string pop();
   string peek() {
       return top->value;
   }
   int getLength() {
       return length;
    }
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_str::push(string item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store item there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}


int main() {

     Stack_str s;
     string item;

     /* Write your code here */
     // Lets the user enter an unknown num of strings and pushes them onto stack
     // The loop stops once the user enters 0
     while (item != "0") {
        getline(cin,item);
        if (item == "0") {
            break;
        }
        s.push(item);
     }
     
     // Displays the num of elements
     cout << s.getLength() << endl;
     // Displays the string on top of the stack and the length of the stack if not empty
     if (s.isEmpty() == false) {
        cout << s.peek() << endl;
        cout << s.getLength() << endl;
     } else {
        cout << "Empty Stack!" << endl;
        cout << s.getLength() << endl;
     }

     return 0;
}

/*
3.6 Lab: Stacks 1 (strings)
Write the C++ implementation of following three member functions of the Stack class:

getLength(): returns the number of elements in the stack
isEmpty(): returns true if the stack is empty, false otherwise
peek(): returns the value at the top of the stack without removing it. Assumes the stack is not empty (no need to check).
The push function is given.

Write code in main() to test these functions. Write a loop to enter an unknown number of strings, one string per line. The loop stops when you enter 0. As you are entering strings, they are to be pushed onto a stack. Once done, display the number of elements on the first line, the value at the top of the stack on the next line, and display the number of elements in the stack again.

*/