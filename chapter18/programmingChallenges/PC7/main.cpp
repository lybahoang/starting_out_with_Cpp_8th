#include <iostream>
#include "DynamicIntStack.h"
using namespace std;

int main()
{
    // Create a dynamic integer stack object.
    DynamicIntStack myStack;

    // Initialize the stack with some values.
    myStack.push(25);
    myStack.push(9);
    myStack.push(30);

    // Display the number of nodes and the value of each node.
    cout << "There are " << myStack.getNumNodes() << " nodes.\n";
    int catchVar;
    while(!myStack.isEmpty())
    {
        myStack.pop(catchVar);
        cout << catchVar << " ";
    }

    return 0;
}