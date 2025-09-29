/**
    The program demonstrates a function that dynamically allocates
    an array and returns the address of the array.
 */
#include <iostream>
using namespace std;

/**
    The arrayAllocator function returns the address of an array of
    integers with a specified size.
    @param size The size of the array.
    @return The address of the array.
 */
int *arrayAllocator(int size)
{
    return new int[size];
}

int main()
{
    // A variable to hold the size of the array.
    int size;

    // Get the size of the array from the user.
    cout << "Enter a size: ";
    cin >> size;

    // Dynamically allocate an array of integers.
    int *arrayPtr = arrayAllocator(size);

    // Initialize the array with some values.
    for (int count = 0; count < size; count++)
    {
        *(arrayPtr + count) = count * 2;
    }

    // Display the array.
    for (int count = 0; count < size; count++)
    {
        cout << *(arrayPtr + count) << "  ";
    }
    
    // Delete the memory.
    delete [] arrayPtr;

    return 0;
}