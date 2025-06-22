#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an object from the IntegerList class.
    IntegerList myList;

    // Add some values to the list.
    for (int count = 0; count < 100; count += 10)
        myList.appendNode(count);

    // Display the values in the list.
    cout << "There are " << myList.countNode() << " values ";
    cout << "in the list, which are\n";
    myList.displayList();
    cout << endl;

    // Insert a node at position 0.
    cout << "\nNow, inserting -10 at position 0.\n";
    myList.insertNodeByPosition(-10, 0);

    // Display the values in the list.
    cout << "There are " << myList.countNode() << " values ";
    cout << "in the list, which are\n";
    myList.displayList();
    cout << endl;

    // Insert a node at position 3.
    cout << "\nNow, insert -25 at position 3.\n";
    myList.insertNodeByPosition(-25, 3);

    // Display the values in the list.
    cout << "There are " << myList.countNode() << " values ";
    cout << "in the list, which are\n";
    myList.displayList();
    cout << endl;

    return 0;
}