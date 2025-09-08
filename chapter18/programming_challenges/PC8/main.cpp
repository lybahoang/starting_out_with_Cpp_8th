#include "DynamicStack.h"
#include "MathStack.h"
#include <iostream>
using namespace std;

// Function prototypes.
void refillData(MathStack<double> * const);

int main()
{
    // Create a pointer to MathStack object of doubles.
    MathStack<double> *myDoubleStackPtr = new MathStack<double>;

    // Fill the stack with some data.
    refillData(myDoubleStackPtr);
    
    // Display the stack.
    myDoubleStackPtr->displayStack();
    cout << endl;

    // Perform add, sub, mul, and div functions.
    cout << "Add: ";
    myDoubleStackPtr->add();
    myDoubleStackPtr->displayStack();
    cout << endl;

    cout << "Sub: ";
    myDoubleStackPtr->sub();
    myDoubleStackPtr->displayStack();
    cout << endl;

    cout << "Mult: ";
    myDoubleStackPtr->mult();
    myDoubleStackPtr->displayStack();
    cout << endl;

    cout << "Div: ";
    myDoubleStackPtr->div();
    myDoubleStackPtr->displayStack();
    cout << endl;

    // Perform addAll function.
    refillData(myDoubleStackPtr);
    myDoubleStackPtr->displayStack();
    cout << endl;
    cout << "Add all: ";
    myDoubleStackPtr->addAll();
    myDoubleStackPtr->displayStack();
    cout << endl;

    // Perform multAll function.
    refillData(myDoubleStackPtr);
    myDoubleStackPtr->displayStack();
    cout << endl;
    cout << "Mult all: ";
    myDoubleStackPtr->multAll();
    myDoubleStackPtr->displayStack();
    cout << endl;

    // Delete dynamically allocated memory.
    delete myDoubleStackPtr;

    return 0;
}

/**
 * Function refillData. The function accepts a pointer to MathStack<double> object, and then
 * pushes onto the object some values.
 */
void refillData(MathStack<double> * const stackPtr)
{
    for (int count = 1; count < 10; count++)
        stackPtr->push(count * 2.5);
}