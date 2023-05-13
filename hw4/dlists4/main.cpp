/*
 Sorted Circular Doubly-Linked List with Sentinel Node
 
 Build and procees a sorted linked list of Park objects.
 The list is sorted in ascending order by the Park code, a unique identifier.

// Written by: A. Student
// Reviewed & Modified by: Rimma Esheva
// IDE: VS Cosw

*/

// Written By: A. Student
// Changed By: Rimma Esheva
// IDE: Xcode


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>  //  toupper()
#include "LinkedList.h"

using namespace std;

void buildList(const string &filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(const LinkedList &list);
void displayManager(const LinkedList &list);

int main()
{

    string inputFileName = "national_parks.txt";
    LinkedList list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/*
 This function reads data about national parks from a file and inserts them
 into a sorted linked list. The list is sorted in ascending order by code.
*/
void buildList(const string &filename, LinkedList &list)
{
    ifstream inputFile(filename);
    cout << "Reading data from \"" << filename << "\"" << endl;

    if(!inputFile)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(inputFile, line))
    {
       int year;
       string code, name, state, dsc;
    
       stringstream temp(line);   // create temp with data from line
       temp >> code;              // read from temp
       temp >> state;
       temp >> year;
       temp.ignore();             // to ignore space in front of name
       getline(temp, name, ';');   // stop reading name at ';'
       temp.ignore();             // to ignore space in front of description
       getline(temp, dsc);
       // create a Park object and initialize it with data from file
       Park aPark(code, state, name, dsc, year);
       list.insertNode(aPark);
    }

    inputFile.close();
}

/* 
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 */
void deleteManager(LinkedList &list)
{
    string targetCode = "";

    cout << endl << " Delete" << endl;
    cout << "=======" << endl;

    while(targetCode != "Q")
    {
        cout << "Enter a park code (or Q to stop deleting):" << endl;
        getline(cin, targetCode);
        targetCode[0] = toupper(targetCode[0]);
        if(targetCode != "Q")
        {
            if(list.deleteNode(targetCode))
                cout << "    " << targetCode << " has been deleted!" << endl;
            else
                cout << "Park \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____" << endl;
}

/*
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */
void searchManager(const LinkedList &list)
{
    string targetCode = "";
    Park aPark;

    cout << endl << " Search" << endl;
    cout <<   "=======" << endl;

    while(targetCode != "Q")
    {
        cout << "Enter a park code (or Q to stop searching):" << endl;
        getline(cin, targetCode);
        targetCode[0] = toupper(targetCode[0]);
        if(targetCode != "Q")
        {
            if(list.searchList(targetCode, aPark))
                aPark.vDisplay();
            else     
               cout << "Park \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____" << endl;
}

/* 
Display manager:
 - displays the number of national parks in this list
 - calls the displayListForw()/displayListBack() function upon request
Input Parameter: list
*/
void displayManager(const LinkedList &list)
{
    string action;
    
    cout << "Number of National Parks in this list: " << list.getLength() << endl;
    cout << "Display list [F/B/N]?" << endl;
    getline(cin, action);
    action[0] = toupper(action[0]);
    if (action == "F")
        list.displayListForw();
    else if (action == "B")
        list.displayListBack();
}
