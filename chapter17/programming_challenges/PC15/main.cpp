#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an IntegerList object.
    IntegerList myList;

    // Initialize the list with some values.
    for (int count = 0; count < 5; count++)
    {
        myList.appendNode(count * 5);
    }

    // Display the values in the list.
    cout << "Here are values in the list.\n";
    myList.displayList();

    // Pop back the list.
    cout << "\nPopping back the list.";
    myList.pop_back();

    // Display the values in the list.
    cout << "\nHere are values in the list.\n";
    myList.displayList();

    return 0;
}