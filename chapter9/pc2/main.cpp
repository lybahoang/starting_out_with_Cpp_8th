#include <iostream>
using namespace std;

/**
    The sortAscending function sorts an array in ascending order
    using the selection sort.
    @param arrayPtr The pointer to an array.
    @param size The size of the array.
 */
void sortAscending(double * const arrayPtr, int size)
{
    for (int startScan = 0; startScan < size - 1; startScan++)
    {
        int minIndex = startScan;
        double minValue = arrayPtr[startScan];

        for (int index = startScan + 1; index < size; index++)
        {
            if (arrayPtr[index] < minValue)
            {
                minIndex = index;
                minValue = arrayPtr[index];
            }
        }

        arrayPtr[minIndex] = arrayPtr[startScan];
        arrayPtr[startScan] = minValue;
    }
}

/**
    The getAverage function returns the average value of an array.
    @param arrayPtr The pointer to an array.
    @param size The size of the array.
    @return The average value of the array.
 */
double getAverage(double *const arrayPtr, int size)
{
    double total = 0;

    for (int count = 0; count < size; count++)
    {
        total += arrayPtr[count];
    }

    return total / size;
}

/**
    The displayArray function displays the contents of an array.
    @param arrayPtr The pointer to an array.
    @param size The size of the array.
 */
void displayArray(const double *const arrayPtr, int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << *(arrayPtr + count) << "  ";
    }
}


int main()
{
    // Get the size of the array.
    int numTests;
    cout << "Enter the number of test scores: ";
    cin >> numTests;

    // Allocate an array of integers.
    double *arrayPtr = new double[numTests];

    // Get the test scores from the user.
    for (int count = 0; count < numTests; count++)
    {
        cout << "Enter test score #" << (count + 1) << ": ";
        cin >> arrayPtr[count];
    }

    // Sort the array of test scores.
    sortAscending(arrayPtr, numTests);

    // Get the average test scores.
    double averageScore = getAverage(arrayPtr, numTests);

    // Display the results.
    cout << "Sorted test scores: ";
    displayArray(arrayPtr, numTests);
    cout << "\nAverage test score: " << averageScore << endl;

    // Delete dynamically allocated memory.
    delete [] arrayPtr;

    return 0;
}