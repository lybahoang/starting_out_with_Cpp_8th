#ifndef SEARCHABLE_VECTOR_H
#define SEARCHABLE_VECTOR_H
#include "SortableVector.h"

template <class T>
class SearchableVector : public SortableVector<T>
{
public:
    // Default constructor.
    SearchableVector() : SortableVector<T>() { };

    // Constructor.
    SearchableVector(int size) : SortableVector<T>(size) { };

    // Copy constructor.
    SearchableVector(const SearchableVector &other);

    // Accessor to find an item.
    int findItem(T value);
    int sortAndSearch(T value);
};

// Copy constructor.
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &other) : SimpleVector<T>(other.getSize())
{
    // Copy the element of the 'other' object.
    for (int count = 0; count < this->getSize(); count++)
        this->arrayPtr[count] = other.arrayPtr[count];
}

/***
 * Function findItem: The function accepts an argument about
 * the value to be searched. The function searches for the value
 * using binary search. The function returns the position of the
 * value if the value is found. Otherwise, it returns -1.
 */
template <class T>
int SearchableVector<T>::findItem(T value)
{
    int startingIndex = 0;                  // Hold the starting index.
    int endingIndex = this->arraySize - 1;  // Hold the ending index.
    int middleIndex = 0;                    // Hold the middle index.

    // A loop to perform binary search.
    while (startingIndex <= endingIndex)
    {   
        // Calculate the middle index.
        middleIndex = (startingIndex + endingIndex) / 2;

        // If the value is at the middle position, the
        // return the middleIndex.
        if (this->arrayPtr[middleIndex] == value)
            return middleIndex;

        // If the 'value' is less than the 'middle' value, 
        // then set the endingIndex to 'middle' - 1.
        if (this->arrayPtr[middleIndex] > value)
            endingIndex = middleIndex - 1;
        // Otherwise, set the startingIndex to 'middle' + 1.
        else
            startingIndex = middleIndex + 1;
    }
    // Return -1 if the value is not found.
    return -1;
}


/***
 * Function sortAndSearch: The function accepts an argument about
 * the value to be searched. The function sorts and searches for 
 * the value using binary search. The function returns the position 
 * of the value if the value is found. Otherwise, it returns -1.
 */
template <class T>
int SearchableVector<T>::sortAndSearch(T value)
{
    // Sort the array by calling the function
    // sortAscending in the base class 'SortableVector'.
    this->sortAscending();

    // Search for the value by calling the function
    // findItem of the class.
    return this->findItem(value);
}


// A specialized template working with strings.
template <>
class SearchableVector<string> : public SortableVector<string>
{
public:
    // Default constructor.
    SearchableVector() : SortableVector<string>() { };

    // Constructor.
    SearchableVector(int size) : SortableVector<string>(size) { };

    // Copy constructor.
    SearchableVector(const SearchableVector &other);

    // Accessor to find an item.
    int findItem(const string &value);
    int sortAndSearch(const string &value);
};

// Copy constructor.
SearchableVector<string>::SearchableVector(const SearchableVector &other) : SortableVector<string>(other.getSize())
{
    // Copy the element of the 'other' object.
    for (int count = 0; count < this->getSize(); count++)
        this->arrayPtr[count] = other.arrayPtr[count];
}

/***
 * Function findItem: The function accepts an argument about
 * the value to be searched. The function searches for the value
 * using binary search. The function returns the position of the
 * value if the value is found. Otherwise, it returns -1.
 */
int SearchableVector<string>::findItem(const string &value)
{
    int startingIndex = 0;                  // Hold the starting index.
    int endingIndex = this->arraySize - 1;  // Hold the ending index.
    int middleIndex = 0;                    // Hold the middle index.

    // A loop to perform binary search.
    while (startingIndex <= endingIndex)
    {   
        // Calculate the middle index.
        middleIndex = (startingIndex + endingIndex) / 2;

        // If the value is at the middle position, the
        // return the middleIndex.
        if (this->arrayPtr[middleIndex] == value)
            return middleIndex;

        // If the 'value' is less than the 'middle' value, 
        // then set the endingIndex to 'middle' - 1.
        if (this->arrayPtr[middleIndex] > value)
            endingIndex = middleIndex - 1;
        // Otherwise, set the startingIndex to 'middle' + 1.
        else
            startingIndex = middleIndex + 1;
    }
    // Return -1 if the value is not found.
    return -1;
}


/***
 * Function sortAndSearch: The function accepts an argument about
 * the value to be searched. The function sorts and searches for 
 * the value using binary search. The function returns the position 
 * of the value if the value is found. Otherwise, it returns -1.
 */
int SearchableVector<string>::sortAndSearch(const string &value)
{
    // Sort the array by calling the function
    // sortAscending in the base class 'SortableVector'.
    this->sortAscending();

    // Search for the value by calling the function
    // findItem of the class.
    return this->findItem(value);
}
#endif