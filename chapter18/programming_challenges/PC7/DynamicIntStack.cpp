#include "DynamicIntStack.h"
#include <new>
#include <iostream>
using namespace std;

/**
 * Constructor: Creates an empty stack.
 */
DynamicIntStack::DynamicIntStack()
{
    top = nullptr;
    numNodes = 0;
}

/**
 * Destructor: Deletes all nodes in the stack.
 */
DynamicIntStack::~DynamicIntStack()
{
    int catchVar;   // To hold the value popped off.

    while (!isEmpty())
        pop(catchVar);
}

/**
 * Operation push(int): Pushes an integer onto the stack.
 * @param num: The integer value to push onto the stack.
 * @return: void.
 */
void DynamicIntStack::push(int num)
{
    try
    {
        // Allocate a new node and assign it the number value.
        StackNode *newNode = new StackNode;
        newNode->value = num;
    
        // Make the new node point to the top node.
        newNode->next = top;
    
        // Update the top to point to the new node.
        top = newNode;
    
        // Update the number of nodes in the stack.
        numNodes++;
    }
    catch(bad_alloc)
    {
        cout << "Error: Cannot allocate memory for new nodes.\n";
    }
}

/**
 * Operation pop(int &): Pops the top value off the stack
 * and assign it to the reference parameter.
 * @param catchVar: The reference parameter.
 * @return: void.
 */
void DynamicIntStack::pop(int &catchVar)
{
    // If the stack is empty, then displays a message.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    // Otherwise, pop the top value off the stack.
    else
    {
        // Assign the top value to the reference parameter.
        catchVar = top->value;

        // Save the node after the top node.
        StackNode *tempNode = top->next;

        // Delete the top node.
        delete top;

        // Update the top node to point to the temporary node.
        top = tempNode;

        // Update the number of nodes in the stack.
        numNodes--;
    }
}

/**
 * Operation isEmpty(): Returns true if the stack is empty,
 * or false otherwise.
 */
bool DynamicIntStack::isEmpty() const
{
    // If the number of nodes is empty, then the stack is empty.
    if (numNodes == 0)
        return true;
    // Otherwise, return false.
    return false;
}

/**
 * Function getNumNodes(): Returns the number of nodes in the stack.
 */
int DynamicIntStack::getNumNodes() const
{ return numNodes; }
