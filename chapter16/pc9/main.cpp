/***
 * This program demonstrates the function findItem
 * which uses binary search.
 * Warning: Assume that the values in an object is in ascending order.
 */

#include "SearchableVector.h"
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5;     // The array size.
    int result;             // To hold search results

    // Create an object from the SearchableVector class,
    // which contains integers.
    SearchableVector<int> myIntVector(SIZE);

    // Initialize the object with some values.
    for (int count = 0; count < SIZE; count++)
        myIntVector[count] = 3 * count;
    
    // Display the values in myIntVector.
    cout << "Here are values in myIntVector.\n";
    myIntVector.displayArray();

    // Search for the value 6 in the array.
    cout << "\n\nNow, I'm searching for 6 in myIntVector.\n";
    result = myIntVector.findItem(6);
    if (result == -1)
        cout << "6 was not found in myIntVector.\n";
    else
    {
        cout << "6 was found in myIntVector at ";
        cout << "position " << result << ".\n";
    }

    // Search for the value 100 in the array.
    cout << "\nNow, I'm searching for 100 in myIntVector.\n";
    result = myIntVector.findItem(100);
    if (result == -1)
        cout << "100 was not found in myIntVector.\n";
    else
    {
        cout << "100 was found in myIntVector at ";
        cout << "position " << result << ".\n";
    }
    return 0;
}