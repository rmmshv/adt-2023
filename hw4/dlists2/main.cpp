/*
CIS 22C: Sorted Circular Doubly-Linked List with Sentinel Node
 
This program:
- Creates a sorted linked list (student name and gpa). The list is sorted in ascending order by name.
- Displays the list forwards(A to Z)
- Deletes nodes from the list
- Displays the list backwards(Z to A)

Your task is to finish writing the following three functions:
- default constructor (reuse code from your previous Lab)
- insertNode()  (reuse code from your previous Lab)
- displayListBack()  (reuse code from your previous Lab)
- deleteNode()
 
 Written by: A. Student
 Reviewed by: Rimma Esheva
 IDE: VS Code
 
*/

#include <iostream>
#include <sstream>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;
    
    buildList(list); // insert data into the list
    cout << "There are " << list.getCount() << " elements in the list." << endl;
    string answer;
    cout << "Delete [Y/N]? ";
    getline(cin, answer);
    if (answer == "Y" || answer == "y")
    {
        string targetName;
        cout << "Enter name to be removed from the list:" << endl;
        getline(cin, targetName);
        cout << targetName << (list.deleteNode(targetName) ? " - deleted!" : " - not found!") << endl;
        cout << "There are " << list.getCount() << " elements in the list." << endl;
    }
    cout << endl;
    list.displayListForw();
    /* Write your code here: display the list from Z to A */
    list.displayListBack();
    return 0;
}

/* **************************************************
This function builds a sorted linked list with data from the keyboard.
The list is sorted in ascending order by the students' names.
It calls the insertNode() function that inserts the new data at the right location in the linked list.
An input line contains the gpa of a student follow by its name (assume it is a single word name)
To stop reading enter "#"
************************************************** */
void buildList(StudentList &list)
{
   string line;
   getline(cin, line);
   while (line != "#")
   {
      stringstream temp(line); // create a stringstream named temp with data from line
      Student newStu;
      temp >> newStu.gpa;  // read gpa from temp
      temp >> newStu.name; // read name from temp
      list.insertNode(newStu);
      getline(cin, line);
   }
    
}