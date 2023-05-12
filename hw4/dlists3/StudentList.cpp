// Sorted Circular Doubly-Linked List with Sentinel Node
// Implementation file for the Student List class
// Reviewed & Modified by: Rimma Esheva
// IDE: VS Code

#include <iostream>         // For cout  and NULL
#include "StudentList.h"
using namespace std;

// **************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
// **************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node
    
    head->stu.gpa = -1;
    head->stu.name = "";
    head->forw = head;
    /* Write your code here */
    head->back = head;
    count = 0;
}

// **************************************************
// display list forwards: shows the value
// stored in each node of the linked list
// pointed to by head. from A to Z
// **************************************************

void StudentList::displayListForw() const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->forw;

    // While pCur points to a node, traverse the list.
    while (pCur != head)
    {
        // Display the value in this node.
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;

        // Move to the next node.
        pCur = pCur->forw;
    }
    cout << endl;
}
// **************************************************
// display list forwards: shows the value
// stored in each node of the linked list
// pointed to by head, from Z to A
// **************************************************

void StudentList::displayListBack() const
{
    ListNode *pCur; 

    pCur = head->back;

    while (pCur != head) {
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;
        pCur = pCur->back;
    }
    cout << endl;
}

// **************************************************
// The insertNode function checks if a node with the
// same key as dataIn's key is found in the list
// If it is found, returns false, meaning that insert
// has failed to add the new data (duplicate!)
// otherwise inserts a node with
// stu copied to its value member, and returns true.
// **************************************************
bool StudentList::insertNode(Student dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    bool success = false;    // Assume dataIn is a duplicate
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->stu = dataIn;

    // Initialize pointers
    pCur = head->forw;
   
    // Find location: skip all nodes whose name is less than dataIn's name
    while (pCur != head && pCur->stu.name < dataIn.name)
    {
        pCur = pCur->forw;
    }
    
   /* Write your code here */
    if (pCur->stu.name == dataIn.name) {
       success = false;
    } else {
        // Insert the new node between pPre and pCur
        ListNode *pPre = pCur->back;     // The previous node
        pPre->forw = newNode;
        newNode->forw = pCur;
        
        /* Write your code here */
        pCur->back = newNode;
        newNode->back = pPre;
        success = true;
        
        // Update the counter
        count++;
    }
    return success;
}

// **************************************************
// Destructor                                       
// This function deletes every node in the list.    
// **************************************************
StudentList::~StudentList()
{
  
}
