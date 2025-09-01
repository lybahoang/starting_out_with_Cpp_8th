#include <iostream>
using namespace std;

// Function prototypes.
void getSize(int *);
double *arrayAllocator(int);
void getScores(double *, int);
void sortScores(double * const, int);
double calcAverageScore(const double * const, int);

int main()
{
    // Variable to hold the size of the array.
    int size;
    // A pointer variable to doubles.
    double *arrPtr = nullptr;

    // Prompt the user for the size of the array.
    getSize(&size);

    // Allocate the array.
    arrPtr = arrayAllocator(size);

    // Prompt user for the scores.
    getScores(arrPtr, size);

    // Sort the scores in ascending order.
    sortScores(arrPtr, size);

    // Calculate the average scores.
    double averageScore = calcAverageScore(arrPtr, size);

    // Display the sorted list of scores.
    cout << "The sorted list of scores: ";
    for (int count = 0; count < size; count++)
    {
        cout << *(arrPtr + count) << " ";
    }
    cout << endl;
    
    // Display the averaged scores.
    cout << "The average score is " << averageScore << endl;

    // Delete the dynamically allocated array.
    delete [] arrPtr;

    return 0;
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
 * Function arrayAllocator(int): The function accepts an integer as the
 * size of an array. It then dynamically allocates an array of doubles
 * with that size.
 * @para: size (int): The size of the array.
 * @return: double *: The pointer to the array.
 */
double *arrayAllocator(int size)
{
    // Initialize a pointer variable to doubles.
    double *ptr = nullptr;

    // Dynamically allocate the array of the specified size.
    ptr = new double[size];

    // Return the pointer.
    return ptr;
}

/***
 * Function getScores(double *, int): The function accepts a pointer to
 * an array of doubles and its size. Then the function prompts the user
 * for the scores.
 * @para: arrPtr (double *): The pointer to the array.
 * @para: size (int): The size of the array.
 */
void getScores(double *arrPtr, int size)
{
    cout << "Enter the scores.\n";
    for (int count = 0; count < size; count++)
    {
        do
        {
            cout << "Test score #" << (count + 1) << ": ";
            cin >> *(arrPtr + count);
            if (*(arrPtr + count) < 0)
            {
                cout << "Sorry. This is an invalid test score.\n";
                cout << "Please enter again.\n";
            }
        } while (*(arrPtr + count) < 0);
    }
}

/***
 * Function sortScores(double *, int): The function accepts a pointer to
 * an array of double and its size and uses a selection sort to sort the
 * array in ascending order.
 * @param arrPtr (double *): The pointer to the array.
 * @param size (int): The size of the array.
 */
void sortScores(double * const arrPtr, int size)
{
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = *(arrPtr + startScan);

        for (int index = startScan + 1; index < size; index++)
        {
            if (minValue > *(arrPtr + index))
            {
                minValue = *(arrPtr + index);
                minIndex = index;
            }
        }
        *(arrPtr + minIndex) = *(arrPtr + startScan);
        *(arrPtr + startScan) = minValue;
    }
}

/***
 * Function calcAverageScore(const double * const, int): The function accepts a pointer
 * to an array of double and its size, and then calculates the average and returns it.
 * @param arrPtr (const double *const): The pointer of the array.
 * @param size (int): The size of the array.
 * @return (double) the average value of the array.
 */
double calcAverageScore(const double * const arrPtr, int size)
{
    double totalScore = 0;

    for (int count = 0; count < size; count++)
    {
        totalScore += *(arrPtr + count);
    }

    return (totalScore / size);
}