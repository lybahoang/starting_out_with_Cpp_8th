#include "NumberList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a NumberList object.
    NumberList myList;

    // Append myList some values.
    for (int count = 8; count < 13; count++)
    {
        myList.appendNode(count * 2.5);
    }

    // Display values in myList.
    cout << "Here are values in myList.\n";
    myList.displayList();

    // Create an array of 3 doubles.
    double doubleArray[] = {25.9, 30.9, 27.1};

    // Merge the array into the linked list.
    myList.mergeArray(doubleArray, 3);

    // Display myList again.
    cout << "\nHere are values in myList.\n";
    myList.displayList();
    return 0;
}