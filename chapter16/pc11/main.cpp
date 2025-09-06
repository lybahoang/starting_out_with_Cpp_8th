#include "SearchableVector.h"
#include <cstdlib>         // For random numbers.
#include <ctime>           // For the seed to generate random numbers.
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5;     // The array size.

    // Create an object from the SearchableVector class.
    SearchableVector<int> myIntVector(SIZE);

    // Generate a sequence of random numbers.
    srand(time(0));

    // Initialize the object with some values.
    for (int count = 0; count < SIZE; count++)
    {
        myIntVector[count] = rand();
    }

    // Display the values in myIntVector.
    cout << "Here are values in myIntVector.\n";
    myIntVector.displayArray();

    // Sort and search for the value 2590.
    cout << "\nSorting and searching for the value 2590.\n";
    int result = myIntVector.sortAndSearch(2590);

    // Display the sorted array.
    cout << "\nHere are values in myIntVector.\n";
    myIntVector.displayArray();
    cout << endl;

    // Display the searching result.
    if (result == -1)
        cout << "2590 was not found.\n";
    else
        cout << "2590 was found at " << result << " position.\n";

    return 0;
}