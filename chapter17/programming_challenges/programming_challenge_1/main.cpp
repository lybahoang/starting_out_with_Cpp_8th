// Programming Challenge 1: Your Own Linked List
// Starting out with C++ (8th) pages 1060.

#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a list of integers.
    IntegerList list;

    // Append 4 nodes to the list.
    list.appendNode(5);
    list.appendNode(25);
    list.appendNode(27);
    list.appendNode(30);

    // Display the list.
    list.displayList();

    // Insert nodes to the list.
    list.insertNode(10);

    // Display the new list.
    list.displayList();

    // Delete a node.
    list.deletingNode(10);

    // Display the new list again.
    list.displayList();

    return 0;
}