#include "SortableVector.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an object from the SortableVector class.
    SortableVector<double> myDoubleVector(5);

    // Initialize the object with some data.
    myDoubleVector[0] = 82.8;
    myDoubleVector[1] = 95.5;
    myDoubleVector[2] = 6.4;
    myDoubleVector[3] = 2.5;
    myDoubleVector[4] = 10.5;
    
    // Display the values in myDoubleVector.
    cout << "Here are values in myDoubleVector.\n";
    myDoubleVector.displayArray();

    // Sort the object.
    cout << "\nSorting the list.\n";
    myDoubleVector.sortAscending();
    myDoubleVector.displayArray();

    return 0;
}