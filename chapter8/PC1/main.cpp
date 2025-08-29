// This program creates and tests a function that dynamically
// allocates an array of integers and returns its address.

#include <iostream>
using namespace std;

// Function prototypes.
int *arrayAllocator(int);
void getSize(int *);
void getValues(int *, int);
void displayArray(const int *, int);

int main()
{
    int size;       // The size of the array.
    int *intArray;  // The pointer to an array of integer.

    // Prompt user for the size of the array.
    getSize(&size);

    // Allocate the array.
    intArray = arrayAllocator(size);

    // Display the array.
    displayArray(intArray, size);

    return 0;
}
/***
 * Function arrayAllocator(int): The function accepts an integer as the
 * size of an array. It then dynamically allocates an array of integers
 * with that size.
 * @para: size (int): The size of the array.
 * @return: int *: The pointer to the array.
 */
int *arrayAllocator(int size)
{
    // Initialize a pointer variable referencing integers.
    int *ptr = nullptr;

    // Dynamically allocate an array of integers with the specified size.
    ptr = new int[size];

    // Prompt the user for the array's values.
    getValues(ptr, size);

    // Returns the address of the array.
    return ptr;
}

/***
 * Function getSize(int *): The function accepts a pointer to an integer, then
 * it asks user for the size of the array, and stores it as the values that the
 * pointer is pointing to.
 * @para: sizePtr (int *): A pointer to an integer.
 */
void getSize(int *sizePtr)
{
    // Prompt user for the size of an integer.
    cout << "Enter the size of the array: ";
    cin >> *sizePtr;
}

/***
 * Function getValues(int *, int): The function accepts a pointer to an array of
 * integer and its size. The function then prompt users for the values of the
 * array.
 * @para: arrPtr (int *): The pointer to the array of integers.
 * @para: size (int): The size of the array.
 */
void getValues(int *arrPtr, int size)
{
    cout << "Enter the values for the array.\n";
    for (int count = 0; count < size; count++)
    {
        cout << "Value #" << (count + 1) << ": ";
        cin >> *(arrPtr + count);
    }
}

/***
 * Function displayArray(const int *, int): The function accepts a pointer to an
 * array of integer and its size. The function then displays the contents of the 
 * array to the screen.
 * @para: arrPtr (int *): The pointer to an array.
 * @para: size (int): The size of the array.
 */
void displayArray(const int *arrPtr, int size)
{
    cout << "The contents in the array are: " << endl;
    for (int count = 0; count < size; count++)
    {
        cout << *(arrPtr + count) << " ";
    }
}