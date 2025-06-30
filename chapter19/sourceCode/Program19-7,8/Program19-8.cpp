// This program demonstrates the recursive function
// for displaying the list's nodes in reverse.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    const int MAX = 10; // Maximum number of values.

    // Define a NumberList object.
    NumberList list;

    // Build the list with a series of numbers.
    for (double x = 1.5; x < MAX; x+=1.1)
        list.appendNode(x);

    // Display the values in the list.
    cout << "Here are the values in the list.\n";
    list.displayList();

    // Display the values in the reverse order.
    cout << "\nHere are the values in reverse order:\n";
    list.displayBackwards();

    return 0;
}