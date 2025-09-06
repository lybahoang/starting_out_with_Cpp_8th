#ifndef SORTABLE_VECTOR_H
#define SORTABLE_VECTOR_H
#include "SimpleVector.h"
#include <string>
using namespace std;

template <class T>
class SortableVector : public SimpleVector<T>
{
public:
    // Default constructor.
    SortableVector() : SimpleVector<T>() { };

    // Constructor.
    SortableVector(int size) : SimpleVector<T>(size) { };

    // Copy constructor.
    SortableVector(const SortableVector &other);

    // Function to sort the vector.
    void sortAscending();
};

// Copy constructor.
template <class T>
SortableVector<T>::SortableVector(const SortableVector &other) : SimpleVector<T>(other.getSize())
{
    // Copy the element of the 'other' object.
    for (int count = 0; count < other.getSize(); count++)
        this->arrayPtr[count] = other.arrayPtr[count];
}

// Function sortAscending: The function sorts the elements in the array
// in an ascending order using the selection sort.
template <class T>
void SortableVector<T>::sortAscending()
{
    // Begin the main loop of the sort.
    for (int start = 0; start < this->arraySize - 1; start++)
    {
        // Find the minimum element in the unsorted part.
        int minIndex = start;
        T minValue = this->arrayPtr[start];

        for (int count = start + 1; count < this->arraySize; count++)
        {
            if (this->arrayPtr[count] < minValue)
            {
                minValue = this->arrayPtr[count];
                minIndex = count;
            }
        }

        // Swap the found minimum element with the first element
        // of the unsorted part.
        T temp = this->arrayPtr[minIndex];
        this->arrayPtr[minIndex] = this->arrayPtr[start];
        this->arrayPtr[start] = temp;
    }
}


// Specialized template working with strings.
template <>
class SortableVector<string> : public SimpleVector<string>
{
public:
    // Default constructor.
    SortableVector() : SimpleVector<string>() { };

    // Constructor.
    SortableVector(int size) : SimpleVector<string>(size) { };

    // Copy constructor.
    SortableVector(const SortableVector &other);

    // Function to sort the vector.
    void sortAscending();
};

// Copy constructor.
SortableVector<string>::SortableVector(const SortableVector &other) : SimpleVector<string>(other.getSize())
{
    // Copy the element of the 'other' object.
    for (int count = 0; count < other.getSize(); count++)
        this->arrayPtr[count] = other.arrayPtr[count];
}

// Function sortAscending: The function sorts the elements in the array
// in an ascending order using the selection sort.
void SortableVector<string>::sortAscending()
{
    // Begin the main loop of the sort.
    for (int start = 0; start < this->arraySize - 1; start++)
    {
        // Find the minimum element in the unsorted part.
        int minIndex = start;
        string minValue = this->arrayPtr[start];

        for (int count = start + 1; count < this->arraySize; count++)
        {
            if (this->arrayPtr[count] < minValue)
            {
                minValue = this->arrayPtr[count];
                minIndex = count;
            }
        }

        // Swap the found minimum element with the first element
        // of the unsorted part.
        string temp = this->arrayPtr[minIndex];
        this->arrayPtr[minIndex] = this->arrayPtr[start];
        this->arrayPtr[start] = temp;
    }
}
#endif