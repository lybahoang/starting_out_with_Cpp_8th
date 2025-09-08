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
        T value;            // The stack node value.
        StackNode *next;    // The next node.
    };

    // The top of the stack.
    StackNode *top;

public:
    // Default constructor.
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
 * Destructor: The destructor deletes all nodes in the stack.
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

        // Move the the next node.
        nodePtr = nextNode;
    }
}

/**
 * Stack operation - push(T).
 * The operation pushes the argument onto the stack.
 * @param item: The item to be pushed.
 */
template <class T>
void DynamicStack<T>::push(T item)
{
    // Allocate a new node and store item there.
    StackNode *newNode = new StackNode;
    newNode->value = item;

    // If the stack is empty, then make newNode the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    // Otherwise, insert newNode as the top node.
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

/**
 * Stack operation - pop(T &).
 * The operation pops the top value off the stack and assigns it into
 * the reference parameter.
 * @param catchVar: The reference parameter to hold the popped-off value.
 */
template <class T>
void DynamicStack<T>::pop(T &catchVar)
{
    // If the stack is empty, then displays a message.
    if (isEmpty())
        cout << "No value to pop. The stack is empty.\n";
    // Otherwise, pop the top value off.
    else
    {
        // Assign the top value into the reference parameter.
        catchVar = top->value;
        
        // Create a temporary variable to hold the node after
        // the top node.
        StackNode *tempNode = top->next;

        // Delete the top node.
        delete top;

        // Make top point to the tempNode.
        top = tempNode;
    }
}

/**
 * Stack operation - isEmpty().
 * The operation returns true if the stack is empty, false otherwise.
 */
template <class T>
bool DynamicStack<T>::isEmpty() const
{
    // If top is a null pointer, then the stack will be empty.
    if (top == nullptr)
        return true;
    // Otherwise, the stack is not empty.
    return false;
}
#endif