#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an integer linked list object
    LinkedList<int> intList;

    // Append some values.
    intList.appendNode(1);
    intList.appendNode(9);

    // Display the list.
    intList.displayList();

    // Insert some values.
    intList.insertNode(5);
    intList.insertNode(3);

    // Display the list.
    cout << endl;
    intList.displayList();

    return 0;
}