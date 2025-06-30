#include <iostream>
using namespace std;

// Function prototype.
template <class T>
void quickSort(T [], int, int);

template <class T>
int partition(T [], int, int);

template <class T>
void mySwap(T &, T &);

int main()
{
    const int SIZE = 6; // Array size.
    int count;          // Loop counter.
    double doubleArray[SIZE] = {5.2, 6.9, 1.2, 25.9, 18.3, 30.9};
    int intArray[SIZE] = {7, 3, 9, 2, 0, 1};

    // Display the array contents.
    cout << "Here are values in doubleArray\n";
    for (count = 0; count < SIZE; count++)
    {
        cout << doubleArray[count] << " ";
    }
    cout << "\nHere are values in intArray\n";
    for (count = 0; count < SIZE; count++)
    {
        cout << intArray[count] << " ";
    }

    // Sort the two arrays.
    quickSort(doubleArray, 0, SIZE - 1);
    quickSort(intArray, 0, SIZE - 1);

    // Display the array contents.
    cout << "\nHere are values in doubleArray\n";
    for (count = 0; count < SIZE; count++)
    {
        cout << doubleArray[count] << " ";
    }
    cout << "\nHere are values in intArray\n";
    for (count = 0; count < SIZE; count++)
    {
        cout << intArray[count] << " ";
    }

    return 0;
}

/**
 * Function quickSort(): sorts an array using quicksort algorithm.
 * @param array: The array to be sorted.
 * @param start: The starting index.
 * @param end: The ending index.
 * @return: void.
 */
template <class T>
void quickSort(T array[], int start, int end)
{
    int pivotPoint;

    if (start < end)
    {
        // Get the pivot point.
        pivotPoint = partition(array, start, end);
        // Sort the first sublist.
        quickSort(array, start, pivotPoint - 1);
        // Sort the second sublist.
        quickSort(array, pivotPoint + 1, end);
    }
}

/**
 * Function partition: Selects the value in the middle of the array
 * set as the pivot. The list is rearranged so all the values less
 * than the pivot are on its left and all the values greater than
 * pivot are on its right.
 * @param array: The array to be partitioned.
 * @param start: The starting index.
 * @param end: The ending index.
 * @return pivotIndex: The index of pivot.
 */
template <class T>
int partition(T array[], int start, int end)
{
    T pivotValue;
    int pivotIndex, mid;

    mid = (start + end) / 2;
    mySwap(array[start], array[mid]);
    pivotIndex = start;
    pivotValue = array[start];
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (array[scan] < pivotValue)
        {
            pivotIndex++;
            mySwap(array[pivotIndex], array[scan]);
        }
    }
    mySwap(array[pivotIndex], array[start]);
    return pivotIndex;
}

/**
 * Function mySwap: The function exchanges the contents of value1 and
 * value2.
 */
template <class T>
void mySwap(T &value1, T &value2)
{
    T temp = value2;
    value2 = value1;
    value1 = temp;
}
