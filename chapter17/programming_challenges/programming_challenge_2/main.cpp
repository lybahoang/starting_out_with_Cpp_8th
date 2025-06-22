#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an Integer List object.
    IntegerList list;

    // Prompt user for the number of values.
    int numOfIntegers = 0;
    int value = 0;

    cout << "How many integers do you want to store? ";
    cin >> numOfIntegers;

    // Get the integers and append it to the list.
    for (int count = 0; count < numOfIntegers; count++)
    {
        cout << "Enter the integer #" << (count + 1) << ": ";
        cin >> value;
        list.appendNode(value);
    }

    // Display the list.
    cout << "The contents of the list are:\n";
    list.print();

    return 0;
}