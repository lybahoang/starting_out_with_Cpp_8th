#include "IntArray.h"

// Constructor.
IntArray::IntArray(int size)
{
    // Set 'size' to the 'arraySize' variable.
    arraySize = size;

    // Make the arrPtr point to an array of integers.
    arrPtr = new int[arraySize];

    // Set 0 to each element in the array.
    for (int count = 0; count < arraySize; count++)
        *(arrPtr + count) = 0;
}

// Copy constructor.
IntArray::IntArray(const IntArray &other)
{
    // Get the other's array size.
    this->arraySize = other.arraySize;

    // Make a new array for this object.
    this->arrPtr = new int[arraySize];

    // Copy elements in the 'other' object
    // into this object.
    for (int count = 0; count < arraySize; count++)
        this->arrPtr[count] = other.arrPtr[count];
}

// Destructor.
IntArray::~IntArray()
{
    if (arrPtr != nullptr)
        delete arrPtr;
}

// Overloaded operator []
int &IntArray::operator[](const int &subscript)
{
    // If the subscript is out of range, then call
    // the subscriptError function.
    if (subscript < 0 || subscript > arraySize - 1)
        subscriptError(subscript);
    // Otherwise, return the value at subscript.
    return arrPtr[subscript];
}

// Function subcsriptError
void IntArray::subscriptError(int sub)
{
    throw InvalidSubscript(sub);
}