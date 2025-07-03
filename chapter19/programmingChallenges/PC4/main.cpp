#include <iostream>
using namespace std;

// Function prototype.
int sum(const int [], int);

int main()
{
    const int SIZE = 5;     // The array size.

    // Create an array of integers.
    int intArray[SIZE] = {25, 9, 30, 27, 1};

    // Display the array.
    for (int count = 0; count < SIZE; count++)
    {
        cout << intArray[count] << " ";
    }

    // Display the sum of the array.
    cout << "\nThe sum of the array is " << sum(intArray, SIZE) << endl;

    return 0;
}
/**
 * Function sum: Calculates and returns the sum of an array of integers.
 * @param array: The array of integers.
 * @param size: The size of the array.
 * @return: The sum of elements in the array.
 */
int sum(const int array[], int size)
{
    // Base case: If the array size is 0 (or empty), then the sum is 0.
    if (size == 0)
        return 0;
    // Recursive case: The sum equals the last element plus the sum of its
    // all previous elements.
    else
        return array[size - 1] + sum(array, size - 1);
}