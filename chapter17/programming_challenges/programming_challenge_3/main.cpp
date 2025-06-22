#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a list with some values.
    IntegerList list1;

    // Append some values to the list1.
    list1.appendNode(1);
    list1.appendNode(9);
    
    // Create another list and initialize it to list1.
    IntegerList list2 = list1;

    // Display contents of list2.
    list2.displayList();

    return 0;
}