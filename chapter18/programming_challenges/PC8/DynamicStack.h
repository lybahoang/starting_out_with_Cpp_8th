/**
 * This is a template class for dynamic stack.
 * Author: Ly Ba Hoang.
 * Date: 07 September 2025.
 * @version 1.
 */

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>
using namespace std;

template <class T>
class DynamicStack
{
protected:
    // Structure for the stack node.
    struct StackNode
    {
        T data;             // The data of the node.
        StackNode *next;    // The pointer to the next node.
    };

    StackNode *top;         // The top of the stack.
    int numNodes;           // The number of nodes in the stack.

public:
    // Constructor.
    DynamicStack()
        { top = nullptr;
          numNodes = 0; }

    // Destructor.
    ~DynamicStack();

    // Stack operations.
    void push(const T &value);
    void pop(T &catchVar);
    bool isEmpty() const;
    
    // Other functions.
    int getNumNodes() const;
    void displayStack() const;
};

/**
 * Destructor. The destructors deletes all nodes in the stack.
 */
template <class T>
DynamicStack<T>::~DynamicStack()
{
    StackNode *nodePtr = top;       // To traverse the stack.
    StackNode *nextNode = nullptr;  // To point to the next node.

    // While nodePtr is not a null pointer, then save the node after nodePtr
    // to nextNode and delete nodePtr.
    while (nodePtr)
    {
        // Save the node after nodePtr to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Move to the next node.
        nodePtr = nextNode;
    }
}

/**
 * Operation push(). The function accepts a const reference argument representing the
 * value to be pushed onto the stack.
 * @param value (const T &): The value to be pushed onto the stack.
 * @return void.
 */
template <class T>
void DynamicStack<T>::push(const T &value)
{  
    // Allocate a new node and store value there.
    StackNode *newNode = new StackNode;
    newNode->data = value;
    
    // Push newNode onto the stack.
    newNode->next = top;

    // Make top point to newNode.
    top = newNode;

    // Update the number of nodes in the stack.
    numNodes++;
}

/**
 * Operation push(T &): The function accepts a reference argument, which is used to 
 * store the data popped out of the stack.
 * @param catchVar (T &): The reference variable to hold the data popped out of the
 * stack.
 * @return void.
 */
template <class T>
void DynamicStack<T>::pop(T &catchVar)
{
    // If the stack is empty, display a message.
    if (isEmpty())
    {
        cout << "The stack is empty." << endl;
    }
    // Otherwise, pop the top value off the stack.
    else
    {
        // Assign the value of the top node to the reference argument.
        catchVar = top->data;

        // Remember the node after the top.
        StackNode *tempNode = top->next;

        // Delete top node.
        delete top;

        // Make top point back to tempNode.
        top = tempNode;

        // Update the number of nodes in the stack.
        numNodes--;
    }
}

/**
 * Operation isEmpty(). The function returns true if the stack is empty. Otherwise,
 * it returns false.
 */
template <class T>
bool DynamicStack<T>::isEmpty() const
{
    // If the stack is empty, returns true.
    if (!top)
        return true;
    // Otherwise, return false.
    return false;
}

/**
 * Function getNumNodes(): The function returns the number of nodes in the stack.
 * @return (int): The number of nodes in the stack.
 */
template <class T>
int DynamicStack<T>::getNumNodes() const
{
    return numNodes;
}

/**
 * Function displayStack(): The function displays the data of the stack to the screen.
 */
template <class T>
void DynamicStack<T>::displayStack() const
{
    StackNode *nodePtr = top;   // To traverse the stack.

    // While the nodePtr is not a null pointer, then display the data of the node.
    while (nodePtr)
    {
        // Display the data in the node.
        cout << nodePtr->data << " ";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}
#endif