#include <iostream>
#include "DynamicStringStack.h"
using namespace std;

int main()
{
    // Create a dynamic string stack.
    DynamicStringStack myStack;

    // Push some string literals to the stack.
    myStack.push("Ly Ba Hoang");
    myStack.push("Ly Ba Hiep");
    myStack.push("Nguyen Thi Dung");

    // Display the number of nodes in the stack.
    cout << "There are " << myStack.getNumNodes();
    cout << " nodes in the stack.\n";

    // Pop the values off and display them.
    string catchVar = "";

    while(!myStack.isEmpty())
    {
        myStack.pop(catchVar);
        if (catchVar == "")
        {
            cout << "Empty string" << endl;
        }
        else
        {
            cout << catchVar << endl;
        }
    }

    // Try to pop off one more item.
    myStack.pop(catchVar);
    
    return 0;
}