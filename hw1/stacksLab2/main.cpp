/**~*~*~*
CIS 22C
Project: Stack of strings (Destructor)

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
       string value;        // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;              // Number of nodes

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   ~Stack_str();                             // Destructor

   // Stack operations
   // bool isEmpty();
   bool push(string);
   // string pop();
   // string peek();
   // int getLength();
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

/**~*~*~*
   Destructor
*~**/
Stack_str::~Stack_str()
{
   StackNode *currNode;

   // Position nodePtr at the top of the stack.
   currNode = top->value;

   // Traverse the list deleting each node.
   while (currNode) 
   {
      cout << currNode->value << " - deleted!" << endl;
      StackNode *temp = currNode;
      currNode = currNode->next;
      currNode = NULL;
      delete temp;
      
      
   }
   cout << "Empty stack!" << endl;
}

int main() {

     Stack_str s;
     string item;
     
     /* Write your code here */
     while (item != "0") {
        getline (cin,item);
        if (item == "0") {
            break;
        }
        s.push(item);
     }
     
     return 0;
}