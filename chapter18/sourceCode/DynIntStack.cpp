// Implementation file for the DynIntStack class.
#include "DynIntStack.h"
#include <iostream>
using namespace std;

/***
 * Destructor.
 * The destructor deletes every node in the list.
 */
DynIntStack::~DynIntStack()
{
    StackNode *nodePtr = nullptr;   // To traverse the stack.
    StackNode *nextNode = nullptr;  // To point to the next node.

    // Position nodePtr at the top of the stack.
    nodePtr = top;

    // Traverse the stack and delete the node.
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

/***
 * Member function - push(int).
 * This function pushes the argument onto the stack.
 */
void DynIntStack::push(int num)
{
    StackNode *nodePtr = nullptr;   // To traverse the stack.

    // Allocate a new node and store num there.
    StackNode *newNode = new StackNode;
    newNode->value = num;
    
    // If there are no nodes in the stack, make newNode
    // the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else    // Otherwise, insert newNode before top.
    {
        newNode->next = top;
        top = newNode;
    }
}

/***
 * Member function - pop(int &).
 * This function pops the value at the top of the stackk
 * off, and copies it into the variable passed as an
 * argument.
 */
void DynIntStack::pop(int &var)
{
    // If the stack is empty, display a message.
    if (isEmpty())
        cout << "The stack is empty.\n";
    else    // Otherwise, pop value off the stack.
    {
        // Assign the value at the top of the stack into
        // the reference parameter.
        var = top->value;
        
        // Save the node after top.
        StackNode *tempNode = top->next;

        // Delete the top.
        delete top;

        // Make tempNode become the top.
        top = tempNode;
    }
}

/***
 * Member function - isEmpty().
 * This function returns true if the stack is empty, or
 * false otherwise.
 */
bool DynIntStack::isEmpty() const
{
    if (top == nullptr)
        return true;
    return false;
}