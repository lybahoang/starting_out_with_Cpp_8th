#include "SimpleVector.h"
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5;  // The number of elements in the array.

    // Create an object from the SimpleVector class.
    SimpleVector<int> myIntVector(SIZE);

    // Initialize values of the array.
    for (int count = 0; count < SIZE; count++)
    {
        myIntVector[count] = 2 * count;
    }

    // Display the values of the array.
    cout << "Here are values in the array.\n";
    myIntVector.displayArray();
    
    // Pop back the array.
    cout << "\nNow, I'll pop back the array.\n";
    myIntVector.pop_back();

    // Display the values of the array.
    cout << "Here are values in the array.\n";
    myIntVector.displayArray();
    
    // Push a value back to the array.
    cout << "\nNow, I'll push 100 back to the array.\n";
    myIntVector.push_back(100);

    // Display the values of the array.
    cout << "Here are values in the array.\n";
    myIntVector.displayArray();

    return 0;
}