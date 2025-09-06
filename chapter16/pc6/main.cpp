#include "IntArray.h"
#include <iostream>
using namespace std;

int main()
{
    // Prompt the user for the size of the array.
    int size;

    cout << "Enter the array size: ";
    cin >> size;

    // Create an object from the IntArray class.
    IntArray myArray(size);

    // Prompt user to enter values for the array.
    int value;

    cout << "Enter values for the array of " << size;
    cout << " elements.\n";
    for (int count = 0; count < size; count++)
    {
        cout << "Enter the value #" << (count + 1) << ": ";
        cin >> value;
        myArray[count] = value;
    }

    // Display the values in the array.
    cout << "\nHere are values in the array.\n";
    for (int count = 0; count < size; count++)
        cout << myArray[count] << " ";

    // Get an element from the array using subscript.
    int subscript;

    cout << "\nWhich subscript do you want to get value from? ";
    cin >> subscript;

    // Get the value at 'subscript'.
    try
    {
        value = myArray[subscript];

        cout << "Value at subscript " << subscript << " is ";
        cout << value;
    }
    catch(IntArray::InvalidSubscript error)
    {
        cout << "SubscriptError: " << error.getInvalidSubscript();
        cout << " an invalid subscript.\n";
    }

    return 0;
}