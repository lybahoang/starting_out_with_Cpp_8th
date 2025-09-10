#include "NumberList.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
    // Create a NumberList of int data type.
    NumberList<int> integerList;

    // Append the list with some values.
    integerList.appendNode(25);
    integerList.appendNode(30);
    integerList.appendNode(1);
    integerList.appendNode(27);

    // Display the list.
    integerList.displayList();

    // Display the largest value in the list.
    cout << "\nLarges value: " << integerList.maxNode() << endl;
    }
    catch (string exceptStr)
    {
        cout << exceptStr << endl;
    }

    return 0;
}