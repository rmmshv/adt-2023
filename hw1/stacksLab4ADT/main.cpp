/**~*~*~*
CIS 22C
Project: Stack ADT

Written by: Rimma Esheva
IDE: VS Code
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

#include "StackADT.h"

using namespace std;

void printInfo();
void processNumbers(string, Stack<int> &);
void printStack(Stack<int> &);

int main()
{
    printInfo();

    //string filename[] = {"in1.txt", "in2.txt", "in3.txt", ""};
    cout << "Enter input file name: " << endl;
    string filename;
    getline(cin, filename); // assume valid
    
    Stack<int> stack;

    processNumbers(filename, stack);
    printStack(stack);

    return 0;
}

/**~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}

/**~*~*~*~*~
This function processes the input file
*~*/
void processNumbers(string filename, Stack<int>& stack){
    ifstream fin;
    fin.open(filename);
    
    int num;
    Stack<int> temp;
    temp.push(INT_MIN);
    
    if (!fin) {
        cout << "There was an error opening \"" << filename << "\". Exiting.\n";
        fin.close();
        exit(EXIT_FAILURE);
    }
    else {
        cout << "\nInput File: " << filename << endl;
        while (fin >> num) {
            //If we read 0, display the number of elements in the stack.
            if (num == 0) {
                cout << "Count: " << stack.getLength() << endl;
            }
            //If we read a positive number we push it onto the stack
            if (num > 1) {
                stack.push(num);
                if (num > temp.peek()) {
                    temp.push(num);
                }
            }
            //If we read 1, display the element at the top of the stack and the largest value in the stack
            if (num == 1) {
                if (stack.isEmpty()) {
                    cout << "Top: Empty" << endl;
                }
                else {
                    cout << "Top: " << stack.peek() << endl;
                    cout << "Max: " << temp.peek() << endl;
                }
            }
            //If we read a negative num, we pop and print the number removed from the stack and the largest value in the stack
            //If there are fewer numbers in the stack, print "Error"
            if(num < 0){
                if (stack.isEmpty()) {
                    cout << "Pop: Empty" << endl;
                } else {
                    cout << "Pop: " << stack.peek() << endl;
                    if (stack.peek() == temp.peek()) {
                        temp.pop();
                    }
                    stack.pop();
                    if (!stack.isEmpty()){
                        cout << "Max: " << temp.peek() << endl;
                    }
                }
            }
        }
    }
   fin.close();
}

// When the end of the file is detected, print "Stack: "
// and pop and print the items left in the stack, if any, or "Empty" otherwise.
void printStack(Stack<int> &stack) {
    cout << "Stack: ";
    if (stack.isEmpty()){
       cout << "Empty";
    }
    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;
}