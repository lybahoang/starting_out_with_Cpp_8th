#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an object from IntegerList class.
    IntegerList *myList = new IntegerList;

    // Add some values to the list.
    for (int count = 0; count < 100; count += 10)
        myList->appendNode(count);

    // Display the values in the list.
    cout << "Here are values in the list.\n";
    myList->displayList();
    cout << endl;

    // Now search for 40 in the list.
    cout << "\nSearch for 40 in the list.\n";
    int result = myList->search(40);

    if (result != -1)
        cout << "40 was found at position " << result << endl;
    else
        cout << "40 was not found in the list.\n";

    // Now search for 95 in the list.
    cout << "\nSearch for 95 in the list.\n";
    result = myList->search(95);

    if (result != -1)
        cout << "95 was found at position " << result << endl;
    else
        cout << "95 was not found in the list.\n";

    // Delete the dynamically allocated memory.
    delete myList;

    return 0;
}