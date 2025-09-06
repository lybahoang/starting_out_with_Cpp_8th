#include "TestScores.h"
#include <iostream>
using namespace std;

int main()
{
    int size;                     // The size of the array.
    double *arrayPtr = nullptr;   // Pointer to an array of scores.

    // Prompt the user for the number of test scores.
    cout << "How many test scores do you have? ";
    cin >> size;

    // Allocate an array of 'size' elements.
    arrayPtr = new double[size];

    // Prompt the user for each score value.
    for (int count = 0; count < size; count++)
    {
        cout << "Enter score #" << (count + 1) << ": ";
        cin >> arrayPtr[count];
    }

    // Create an object from the TestScore class.
    TestScores *myScores = new TestScores(arrayPtr, size);

    // Display the test score values.
    cout << "\nHere are test score values.\n";
    for (int count = 0; count < size; count++)
        cout << (*myScores)[count] << " ";

    // Display the average score.
    cout << "\nAverage Score: " << myScores->getAverageScore() << endl;

    return 0;
}