// Specification file for the Stack template class.
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *stackArray;      // Pointer to the stack array.
    int stackSize;      // The stack size.
    int top;            // Indicates the top of the stack.

public:
    // Constructor.
    Stack(int);

    // Copy constructor.
    Stack(const Stack &);

    // Destructor.
    ~Stack();

    // Stack operations.
    void push(T);
    void pop(T &);
    bool isFull() const;
    bool isEmpty() const;
};

/***
 * Constructor.
 */
template <class T>
Stack<T>::Stack(int size)
{
    stackArray = new T[size];
    stackSize = size;
    top = -1;
}

/***
 * Copy constructor.
 */
template <class T>
Stack<T>::Stack(const Stack &other)
{
    // Create the stack array.
    if (other.stackSize > 0)
        stackArray = new T[other.stackSize];
    else
        stackArray = nullptr;
    
    // Copy the stack size.
    stackSize = other.stackSize;

    // Copy the stack contents.
    for (int count = 0; count < stackSize; count++)
        stackArray[count] = other.stackArray[count];
    
    // Set the top of the stack.
    top = other.top;
}

/***
 * Destructor.
 */
template <class T>
Stack<T>::~Stack()
{
    if (stackSize > 0)
        delete [] stackArray;
}

/***
 * Member function - push.
 * This function pushes the argument onto the stack.
 */
template <class T>
void Stack<T>::push(T item)
{
    if (isFull())
        cout << "The stack is full.\n";
    else
    {
        top++;
        stackArray[top] = item;
    }
}

/***
 * Member function - pop().
 * This function pops the value at the top of the stack off,
 * and copies it into the variable passed as an argument.
 */
template <class T>
void Stack<T>::pop(T &variable)
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else
    {
        variable = stackArray[top];
        top--;
    }
}

/***
 * Member function - isFull().
 * This function returns true if the stack is full, or
 * false otherwise.
 */
template <class T>
bool Stack<T>::isFull() const
{
    if (top == stackSize - 1)
        return true;
    return false;
}

/***
 * Member function - isEmpty().
 * This function returns true if the stack is empty,
 * or false otherwise.
 */
template <class T>
bool Stack<T>::isEmpty() const
{
    if (top == -1)
        return true;
    return false;
}
#endif