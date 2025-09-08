#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#include <iostream>
using namespace std;

template <class T>
class DynamicStack
{
private:
    // Structure for the stack node.
    struct StackNode
    {
        T value;            // Value in the stack node.
        StackNode *next;    // Pointer to the next node.
    };

    // Pointer to the top of the stack.
    StackNode *top;

public:
    // Constructor.
    DynamicStack()
        { top = nullptr; }
    
    // Destructor.
    ~DynamicStack();

    // Stack operations.
    void push(T);
    void pop(T &);
    bool isEmpty() const;
};

/***
 * Member function - push(T).
 * This function pushes the argument onto the stack.
 */
template <class T>
void DynamicStack<T>::push(T item)
{
    // Allocate a new node and store item there.
    StackNode *newNode = new StackNode;
    newNode->value = item;

    // If there are no nodes in the list, then make
    // newNode become the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    // Otherwise, insert newNode as the top of the stack.
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

/***
 * Member function - pop(T &).
 * This function pops the top node of the stack off and
 * assigns it into the reference parameter.
 */
template <class T>
void DynamicStack<T>::pop(T &var)
{
    // If the stack is empty, then display a message.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    // Otherwise, pop the top off the stack.
    else
    {
        // A temporary stack node to save the node after
        // the top.
        StackNode *tempNode = top->next;

        // Assign the value of the top node into var.
        var = top->value;

        // Delete the top node.
        delete top;

        // Make top point to the tempNode.
        top = tempNode;
    }
}

/***
 * Member function - isEmpty().
 * This function returns true if the stack is empty, or 
 * false otherwise.
 */
template <class T>
bool DynamicStack<T>::isEmpty() const
{
    // If top is a null pointer, then the stack is empty.
    if (top == nullptr)
        return true;
    // Otherwise, returns false.
    return false;
}

/***
 * Destructor.
 * The destructor deletes all nodes in the stack.
 */
template <class T>
DynamicStack<T>::~DynamicStack()
{
    StackNode *nodePtr = nullptr;   // To traverse the stack.
    StackNode *nextNode = nullptr;  // To save the next node.

    // Position nodePtr at the top of the stack.
    nodePtr = top;

    // While nodePtr is not a null pointer, then deletes the node.
    while (nodePtr != nullptr)
    {
        // Save the node after nodePtr to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Move to the next node.
        nodePtr = nextNode;
    }
}
#endif