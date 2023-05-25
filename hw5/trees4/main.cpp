// BST ADT
// Smallest/Largest
// Name <write your name here>

#include "BinarySearchTree.h"  
#include <iostream>
#include <string>

using namespace std;

void buildBST(int n, BinarySearchTree<int> &);
void hDisplay(int &);
void vDisplay(int &);


int main()
{
    BinarySearchTree<int> bst;
    
    int n;
    char option;
    
    cout << "What is the number of nodes in the BST? " << endl;
    cin >> n;
    cout << "Find Smallest or Largest[S/L]? " << endl;
    cin >> option;
    
    buildBST(n, bst);
    
    if ( n < 15 ){
       cout << "  Inorder: ";
       bst.inOrder(hDisplay);
       cout << endl;
    }
    if ( option == 'S' || option == 's')
    {
        int minVal;
        bst.findSmallest(minVal);
        cout << "Smallest: " << minVal << endl;
    }
    else if ( option == 'L' || option == 'l')
    {
        int maxVal;
        bst.findLargest(maxVal);
        cout << "Largest: " << maxVal << endl;
    }
            
    return 0;
}  

/*
 buildBST: builds a binary search tree
 of integers
*/
void buildBST(int n, BinarySearchTree<int> &bst)
{
    int item;
    
    while(n--)
    {
        item = rand( ) % 30 + 10;
        bst.insert(item);
    }
}

/*
 horizontal display: all items on one line
*/
void hDisplay (int &item)
{
    cout << item << " ";
}

/*
 vertical display: one item per line
*/
void vDisplay (int &item)
{
    cout << item << endl;
}

