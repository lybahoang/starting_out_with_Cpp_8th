#include <iostream>
#include "StaticStack.h"
using namespace std;

int main()
{
    const int MAX_ELEMENTS = 5;     // The maximum number of elements in the stack.
    int catchVar;                   // To hold the value popped off from the stack.

    // Create an integer statick stack.
    StaticStack<int> iStack(MAX_ELEMENTS);

    // Push some values onto the stack.
    for (int count = 0; count < 5; count++)
        iStack.push(count);

    // Attempt to push another value to the stack.
    cout << "Push one more value onto the stack.\n";
    iStack.push(MAX_ELEMENTS);

    // Pop and display the values in the stack.
    cout << "\nHere are values in the stack.\n";
    while(!iStack.isEmpty())
    {
        iStack.pop(catchVar);
        cout << catchVar << " ";
    }

    return 0;
}