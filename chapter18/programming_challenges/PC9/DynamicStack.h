/**
 * This is a generic template class for dynamic stacks with some basic operations.
 * @author Ly Ba Hoang.
 * @date 09 September, 2025.
 */

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>
using namespace std;

template <class T>
class DynamicStack
{
private:
    // A structure for the stack node.
    struct StackNode
    {
        T data;             // The data of the node.
        StackNode *next;    // The pointer to the next node.
    };

    StackNode *top;         // The top of the stack.

public:
    // Constructor.
    DynamicStack()
        { top = nullptr; }
    
    // Destructor.
    ~DynamicStack();

    // Basic stack operations.
    void push(const T &);
    void pop(T &);
    bool isEmpty() const;
};

/**
 * Destructor. The destructor deletes all nodes in the stack.
 */
template <class T>
DynamicStack<T>::~DynamicStack()
{
    StackNode *nodePtr = top;       // To traverse the stack.
    StackNode *nextNode = nullptr;  // To point ot the next node.

    // While nodePtr is not nullptr, then deletes the node.
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
 * Operation push(const T &): The function accepts a const reference argument and then
 * pushes the argument onto the stack.
 * @param value (const T &): The data the is going to be onto the stack.
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
    top = newNode;
}

/**
 * Operation pop(T &): The function accepts a reference to a variable, which is used to
 * store the top value popped off the stack.
 * @param catchVar (T &): The variable to hold the popped off value.
 * @return void.
 */
template <class T>
void DynamicStack<T>::pop(T &catchVar)
{
    // If the stack is empty, then display a message saying that the stack is empty.
    if (isEmpty())
    {
        cout << "Cannot pop. The stack is empty." << endl;
    }
    // Otherwise, pop the top value off the stack.
    else
    {
        // Store the popped-off value to the reference parameter.
        catchVar = top->data;

        // Save the node right after the top node.
        StackNode *tempNode = top->next;

        // Delete the top node.
        delete top;

        // Update top so that it points to the next node.
        top = tempNode;
    }
}

/**
 * Operation isEmpty(). The function returns true if the stack is empty. Otherwise,
 * it returns false.
 * @param void.
 * @return void.
 */
template <class T>
bool DynamicStack<T>::isEmpty() const
{
    // If top is nullptr, then the stack is empty, and so returns true.
    if (!top)
        return true;
    // Otherwise, return false.
    return false;
}
#endif