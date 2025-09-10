#include <iostream>
using namespace std;

bool isMember(const int *arrPtr, int size, int searchValue)
{
    // Base case: If the array is empty, returns false.
    if (size == 0)
    {
        return false;
    }

    // Base case: If the first element matches, returns true.
    if ((*arrPtr) == searchValue)
    {
        return true;
    }

    // Recursive step: Call function on the sub array.
    return isMember(arrPtr + 1, size - 1, searchValue);
}

int main()
{
    // Create an integer array of 6 elements.
    const int SIZE = 6;
    int intArray[6] = {25, 30, 27, 5, 9, 1};

    // Check if 25 is in the array.
    cout << "Is 25 in the array? ";
    cout << (isMember(intArray, SIZE, 25) ? "Yes" : "No") << endl;

    // Check if 100 is in the array.
    cout << "Is 100 in the array? ";
    cout << (isMember(intArray, SIZE, 100) ? "Yes" : "No") << endl;

    return 0;
}