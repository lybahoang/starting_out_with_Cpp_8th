#include <iostream>
using namespace std;

// Function prototypes.
void getSize(int *);
double *arrayAllocator(int);
void getScores(double *, int);
void sortScores(double *, int);
double *calcAverageScore(const double * const, int);

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