#include <iostream>
#include "DynamicIntStack.h"
#include "MathStack.h"
using namespace std;

int main()
{
    // Create a MathStack object.
    MathStack myStack;

    // Initialize the stack with some values.
    myStack.push(32);
    myStack.push(16);
    myStack.push(8);
    myStack.push(4);
    myStack.push(2);
    myStack.push(1);

    // Display the number of nodes and the value of each node.
    cout << "There are " << myStack.getNumNodes() << " nodes.\n";
    myStack.displayStack();
    cout << endl;

    // Perform addition on the top two values of the stack.
    cout << "Addition: ";
    myStack.add();

    // Display the stack again.
    myStack.displayStack();
    cout << endl;

    // Perform subtraction on the top two values of the stack.
    cout << "Subtraction: ";
    myStack.sub();

    // Display the stack again.
    myStack.displayStack();
    cout << endl;

    // Perform multiplication on the top two values of the stack.
    cout << "Multiplication: ";
    myStack.mult();

    // Display the stack again.
    myStack.displayStack();
    cout << endl;

    // Perform division on the top two values of the stack.
    cout << "Division: ";
    myStack.div();

    // Display the stack again.
    myStack.displayStack();
    cout << endl;

    // Push some additional values to the stack.
    myStack.push(25);
    myStack.push(27);
    myStack.push(5);
    myStack.push(30);
    cout << "New stack: ";
    myStack.displayStack();

    // Perform the function addAll.
    cout << "\nAdd all: ";
    myStack.addAll();

    // Display the stack.
    myStack.displayStack();
    cout << endl;

    // Push some additional values to the stack.
    myStack.push(25);
    myStack.push(27);
    myStack.push(5);
    myStack.push(30);
    cout << "New stack: ";
    myStack.displayStack();

    // Perform the function multAll.
    cout << "\nMultiply add: ";
    myStack.multAll();

    // Display the stack.
    myStack.displayStack();
    return 0;
}