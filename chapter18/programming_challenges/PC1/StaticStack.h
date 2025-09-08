#ifndef STATIC_STACK_H
#define STATIC_STACK_H
#include <iostream>
using namespace std;

template <class T>
class StaticStack
{
private:
    T *stackArray;      // Points to the stack array.
    int stackSize;      // The stack size.
    int top;            // Indicates the top of the stack.

public:
    // Constructor.
    StaticStack(int);

    // Copy constructor.
    StaticStack(const StaticStack &);

    // Destructor.
    ~StaticStack();

    // Stack operations.
    void push(T);
    void pop(T &);
    bool isFull() const;
    bool isEmpty() const;
};

/***
 * Constructor.
 * The constructor gets the size of the stack and allocates
 * an stack array.
 */
template <class T>
StaticStack<T>::StaticStack(int size)
{
    // Allocate the stack array.
    stackArray = new T[size];

    // Set the stack size.
    stackSize = size;

    // Set the top of the stack.
    top = -1;
}

/***
 * Copy constructor.
 * The copy constructor copies another StaticStack object's 
 * attributes into this object.
 */
template <class T>
StaticStack<T>::StaticStack(const StaticStack &other)
{
    // Allocate the stack array.
    this->stackArray = new T[other.stackSize];

    // Copy the stack size.
    this->stackSize = other.stackSize;

    // Copy the stack array.
    for (int count = 0; count < stackSize; count++)
        this->stackArray[count] = other.stackArray[count];
    
    // Copy the top position.
    this->top = other.top;
}

/***
 * Destructor.
 * The destructor deletes the stack array.
 */
template <class T>
StaticStack<T>::~StaticStack()
{
    if (this->stackArray != nullptr)
        delete [] stackArray;
}

/***
 * Member function - push(T).
 * The function pushes the argument onto the stack.
 */
template <class T>
void StaticStack<T>::push(T item)
{
    // If the stack is full, then displays a message.
    if (this->isFull())
        cout << "The stack is full.\n";
    // Otherwise, pushes the argument onto the stack.
    else
    {
        top++;
        stackArray[top] = item;
    }
}

/***
 * Member function - pop(T &).
 * The function pops an item off the stack and assings
 * it into the reference parameter.
 */
template <class T>
void StaticStack<T>::pop(T &catchVar)
{
    // If the stack is empty, then displays a message.
    if (this->isEmpty())
        cout << "The stack is empty.\n";
    // Otherwise, pops the top item off the stack.
    else
    {
        catchVar = stackArray[top];
        top--;
    }
}

/***
 * Member function - isFull.
 * The function returns true if the stack is full, or
 * false otherwise.
 */
template <class T>
bool StaticStack<T>::isFull() const
{
    if (top == stackSize - 1)
        return true;
    return false;
}

/***
 * Member function - isEmpty.
 * The function returns true if the stack is empty, or
 * false otherwise.
 */
template <class T>
bool StaticStack<T>::isEmpty() const
{
    if (top == -1)
        return true;
    return false;
}
#endif