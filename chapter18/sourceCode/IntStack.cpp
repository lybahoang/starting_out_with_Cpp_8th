// Implementation file for the IntStack class.
#include <iostream>
#include "IntStack.h"
using namespace std;

/***
 * Constructor
 * This constructor creates an empty stack. The size
 * parameter is the size of the stack.
 */
IntStack::IntStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

/***
 * Copy constructor
 */
IntStack::IntStack(const IntStack &other)
{
    // Create the stack array.
    if (other.stackSize > 0)
        stackArray = new int[other.stackSize];
    else
        stackArray = nullptr;
    
    // Copy the stackSize attribute.
    stackSize = other.stackSize;

    // Copy the stack contents.
    for (int count = 0; count < stackSize; count++)
        stackArray[count] = other.stackArray[count];

    // Set the top of the stack.
    top = other.top;
}

/***
 * Destructor
 */
IntStack::~IntStack()
{
    delete [] stackArray;
}

/***
 * Member function - push
 * The function pushes the argument onto the stack.
 */
void IntStack::push(int value)
{
    if (isFull())
        cout << "The stack is full.\n";
    else
    {
        top++;
        stackArray[top] = value;
    }
}

/***
 * Member function - pop
 * The function pops the value at the top of the stack
 * off, and copies it into the variable passed as an
 * argument.
 */
void IntStack::pop(int &var)
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
    {
        var = stackArray[top];
        top--;
    }
}

/***
 * Member function - isFull
 * The function returns true if the stack is full, or
 * false otherwise.
 */
bool IntStack::isFull() const
{
    if (top == stackSize - 1)
        return true;
    else
        return false;
}

/***
 * Member function - isEmpty
 * The function returns true if the stack is empty, or
 * false otherwise.
 */
bool IntStack::isEmpty() const
{
    if (top == -1)
        return true;
    else
        return false;
}

