#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a list
    IntegerList list;

    // Append some values.
    list.appendNode(1);
    list.appendNode(9);
    list.appendNode(25);
    list.appendNode(27);
    list.appendNode(30);

    // Display the origial list.
    cout << "Original: ";
    list.display();

    // Display the list in reversed order.
    list.reverse();
    cout << "\nReverse: ";
    list.display();

    return 0;
}