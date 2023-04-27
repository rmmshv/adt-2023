/**~*~*~*~*
   Stack template
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

public:
    // Constructor
    Stack() { top = NULL; length = 0; }
    // Destructor
    ~Stack();

    // Stack operations:
    // push()
    bool push(T);
    // pop()
    T pop();
    // peek()
    T peek();
    // isEmpty()
    bool isEmpty() { 
        if (length == 0) {
            return true;
        } else {
            return false;
        }
     }
    // getLength()
    T getLength() { return length; }
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
    template <class T>
    bool Stack<T>::push(T item) {
        StackNode *newNode;

        newNode = new StackNode;
        if (!newNode) {
            return false;
        }
        newNode->value = item;

        newNode->next = top;
        top = newNode;
        length++;

        return true;
    }

template <class T>
T Stack<T>::peek() {
    if (top == NULL) {
        return T();
    }
    return top->value;
}

/**~*~*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/
template <class T>
T Stack<T>::pop() {
    if (top == NULL) {
        // stack is empty, return default value
        return T();
    }
    T item = top->value;
    StackNode *temp = top;
    top = top->next;
    delete temp;
    length--;

    return item;
}


/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/
template <class T>
Stack<T>::~Stack() {
    StackNode *currNode = top;
    while (currNode != NULL) {
        StackNode *temp = currNode;
        currNode = currNode->next;
        delete temp;
    }
}


#endif
