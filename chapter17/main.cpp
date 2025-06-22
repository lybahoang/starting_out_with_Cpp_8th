#include "NumberList.h"
#include <iostream>
using namespace std;

int main()
{
    // Define a NumberList object.
    NumberList list;

    // Append some values to the list.
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);

    // Display the list.
    cout << "Here are the intial values:\n";
    list.displayList();
    cout << endl;

    // Delete the middle node.
    cout << "Now deleting the node in the middle.\n";
    list.deleteNode(7.9);

    // Display the values in the list.
    cout << "Here are nodes left.\n";
    list.displayList();
    cout << endl;

    return 0;
}