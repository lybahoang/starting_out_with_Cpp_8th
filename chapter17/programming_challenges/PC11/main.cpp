#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a linked list of integers.
    LinkedList<int> integerList;

    // Append the list some values.
    for (int count = 0; count < 10; count++)
    {
        integerList.appendNode(count * 2);
    }

    // Display the values in the list.
    cout << "Here are values in the list.\n";
    integerList.display();

    // Search for the value 10 in the list.
    cout << "\n\nSearching for 10 in the list.\n";
    cout << "Its position is " << integerList.search(10);
    cout << (integerList.search(10) ? "\n" : " (Not in the list)\n");

    // Search for the value 25 in the list.
    cout << "Searching for 25 in the list.\n";
    cout << "Its position is " << integerList.search(25);
    cout << (integerList.search(25) ? "\n" : " (Not in the list)\n");

    return 0;
}