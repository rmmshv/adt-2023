// Specification file for the BinaryTree class
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Data
{
    int num;
   // more fields could be added if needed
};

class BinaryTree
{
private:
   struct Node
   {
      Data data;     // The value in this node
      Node *left;    // To point to the left node
      Node *right;   // To point to the right node
   };

   Node *root;       // root of the tree
   int count;        // number of nodes in the tree

public:
   // Constructor
   BinaryTree();

   // Destructor
   ~BinaryTree();

   // Binary Tree operations
   void insert(Data dataIn);
   void inOrder() const;
   void postOrder() const;
   void preOrder() const;



private:
    void _inOrder(Node *root) const;
    void _preOrder(Node *root) const;
    void _postOrder(Node *root) const;




    void _destroy(Node *root);
};
#endif
