// BST ADT
// Created by A. Student
// Modified by: Rimma Esheva
 
#include "BinarySearchTree.h"  
#include "Park.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

void displayManager(const BinarySearchTree<Park> &);
void buildBST(const string &filename, BinarySearchTree<Park> &bst);
void searchManager(const BinarySearchTree<Park> &bst);


int main()
{
    string filename;
    BinarySearchTree<Park> bst;

    cout << "What is the input file's name? ";
    getline(cin, filename);
    buildBST(filename, bst);
    displayManager(bst);
    searchManager(bst);
   
    return 0;
}

/*
Display manager: traversals, count, indented tree, and inner nodes
Input Parameter: bst
*/
void displayManager(const BinarySearchTree<Park> &bst)
{
   
    string option;
    
    // count
    cout << "Display count [Y/N]?" << endl;
    getline(cin, option);
    option[0] = toupper(option[0]);
    if (option == "Y")
    {
        cout << "The number of nodes in the BST is ";
        cout << bst.getCount() << endl;
    }
    
    // traversals
    cout << "Display Tree [In/Pre/posT/N]?" << endl;
    getline(cin, option); // I, P, T or N
    option[0] = toupper(option[0]);
    switch (option[0])
    {
       case 'I':
        cout << endl << "Inorder:" << endl;
        bst.inOrder(hDisplay);
        cout << endl;
        break;
       case 'P': 
        cout << endl << "Preorder:" << endl;
        bst.preOrder(hDisplay);
        cout << endl;
        break;  
       case 'T':
        cout << endl << "Postorder:" << endl;
        bst.postOrder(hDisplay);
        cout << endl;
        break;
       case 'N':
        break;
       default:
        cout << "Invalid option!" << endl;
        break;
    }

    // Indented Tree
    cout << "Display Indented List [Y/N]?" << endl;
    getline(cin, option);
    option[0] = toupper(option[0]);
    if (option == "Y") 
    {
        cout << "Indented List:" << endl;
        bst.printTree(iDisplay);
        cout << endl;
    }
    
    // Inner Nodes
    cout << "Display Inner Nodes [Y/N]?" << endl;
    getline(cin, option);
    option[0] = toupper(option[0]);
    if (option == "Y")
    {
        cout  << "Inner Nodes:" << endl;
        bst.printInnerNodes(kDisplay);
        cout << endl;
    }
    
}

/*
 buildBST: builds a binary search tree
*/
void buildBST(const string &file, BinarySearchTree<Park> &bst)
{
    ifstream fin(file);
    cout << "Reading data from \"" << file << "\"" << endl;
    if (!fin)
    {
        cout << "Error opening the input file: \"" << file << "\"" << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while (getline(fin, line))
    {
        int year;
        string code, name, state, desc;
        stringstream temp(line);
        temp >> code;
        temp >> state;
        temp >> year;
        temp.ignore();
        getline(temp, name, ';');
        temp.ignore();
        getline(temp, desc);
        Park aPark(code, state, name, desc, year);
        bst.insert(aPark);
    }
    fin.close();
}

/*
 searchManager
*/
void searchManager(const BinarySearchTree<Park> &bst)
{
    string targetCode;
    Park aPark;
    cout << "\n Search\n";
    cout << "=======\n";
    while (toupper(targetCode[0]) != 'Q')
    {
        cout << "Enter a park code (or Q to stop searching):" << endl;
        getline(cin, targetCode);
        if (toupper(targetCode[0]) != 'Q')
        {
            Park target; 
            std::transform(targetCode.begin(), targetCode.end(), targetCode.begin(), ::toupper);
            target.setCode(targetCode);
            if (bst.search(target, aPark))
                vDisplay(aPark);
            else
                cout << "Park \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
}