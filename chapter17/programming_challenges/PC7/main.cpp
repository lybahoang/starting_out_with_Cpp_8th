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
    
    // Delete a node at position 3.
    cout << "\nNow, delete a node at position 3.\n";
    myList.removeByPosition(3);
    
    // Display the values in the list.
    cout << "There are " << myList.countNode() << " values ";
    cout << "in the list, which are\n";
    myList.displayList();
    cout << endl;

    return 0;
}