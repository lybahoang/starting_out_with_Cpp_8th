#include "DynamicStringStack.h"
#include <new>
#include <iostream>

/**
 * Operation push(string): Pushes a string onto the stack.
 * @param item: The string to be pushed.
 * @return: void.
 */
void DynamicStringStack::push(string item)
{
    try
    {
        // Allocate a new node and assign it the item value.
        StackNode *newNode = new StackNode;
        newNode->value = item;
        
        // Point the new node to the top of the stack.
        newNode->next = top;
    
        // Update the top to point to the new node.
        top = newNode;
    
        // Update the number of nodes.
        numNodes++;
    }
    // Handle if the memory is not allocated successfully.
    catch (bad_alloc)
    {
        cout << "Error: Cannot allocate memory for new node.\n";
    }
}

/**
 * Operation pop(string &): Pops the top item off the stack and assign the
 * item value to the reference parameter.
 * @param catchVar: The reference parameter.
 * @return: void.
 */
void DynamicStringStack::pop(string &catchVar)
{
    // If the stack is empty, then displays a message.
    if (isEmpty())
    {
        cout << "Cannot pop. The stack is empty.\n";
    }
    // Otherwise, pop the top item off the stack.
    else
    {
        // Assign the top item value to the reference parameter.
        catchVar = top->value;

        // Remember the node after the top node.
        StackNode *tempNode = top->next;

        // Delete the top node.
        delete top;
        
        // Update the top to point to the temporary node.
        top = tempNode;

        // Update the number of nodes.
        numNodes--;
    }
}

/**
 * Operation isEmpty(): Returns true if the stack is empty, or false
 * if the stack is not empty.
 */
bool DynamicStringStack::isEmpty() const
{
    // If the number of nodes is equal to zero, then the stack is empty.
    if (numNodes == 0)
        return true;
    // Otherwise return false.
    return false;
}

/**
 * Function getNumNodes: Returns the number of nodes in the stack.
 */
int DynamicStringStack::getNumNodes() const
{ return numNodes; }