#include "TestScores.h"

/***
 * Function subscriptError: The function throws an object
 * of the class InvalidSubscript as an exception when the
 * subscript is invalid.
 */
void TestScores::subscriptError(int sub)
{
    // If the 'sub' is out of range, then throws an
    // exception.
    if (sub > arraySize - 1 || sub < 0)
        throw InvalidSubscript(sub);
}

/***
 * Function scoreError: The function throws an object
 * of the class InvalidScore as an exception when the
 * score value is negative or larger than 100.
 */
void TestScores::scoreError(double score)
{
    if (score < 0 || score > 100)
        throw InvalidScore(score);
}

/***
 * Constructor: The constructor accepts an array
 * of test scores and the size of the array and then
 * stores the array in the 'scoreArray' variable.
 */
TestScores::TestScores(double *inputArray, int size)
{
    // Store 'size' in 'arraySize'.
    arraySize = size;

    // Copy the scores in 'inputArray' into 'scoreArray'.
    scoreArray = new double[arraySize];
    for (int count = 0; count < arraySize; count++)
    {
        // If the score values in 'inputArray' is invalid, then
        // call the scoreError function.
        if (inputArray[count] < 0 || inputArray[count] > 100)
        {
            scoreError(inputArray[count]);
        }
        // Otherwise, copy the score value.
        this->scoreArray[count] = inputArray[count];
    }
}

/***
 * Copy constructor: The constructor is used when the objects
 * are used in assignment statement.
 */
TestScores::TestScores(const TestScores &other)
{
    // Copy the array size.
    this->arraySize = other.arraySize;

    // Copy the score values.
    for (int count = 0; count < arraySize; count++)
        this->scoreArray[count] = other.scoreArray[count];
}

/***
 * Overloaded operator[]: The function accepts an integer about
 * the subscript and returns the test score value at this subscript.
 */
double &TestScores::operator[](int subscript)
{
    // If the 'subscript' is invalid, then throw an object
    // of the class InvalidSubscript as an exception.
    if (subscript < 0 || subscript > arraySize - 1)
        subscriptError(subscript);
    // Otherwise, return the test score value.
    return scoreArray[subscript];
}

/***
 * Function getAverageScore: The function returns the average score
 * of the test.
 */
double TestScores::getAverageScore() const
{
    // An accumulator to calculate the total score.
    double totalScore = 0;

    // Calculate the total score.
    for (int count = 0; count < arraySize; count++)
        totalScore += scoreArray[count];
    
    // Return the average score.
    return totalScore / arraySize;
}

/***
 * Destructor: The destructor deletes the dynamically
 * allocated memory if necessary.
 */
TestScores::~TestScores()
{
    if (scoreArray != nullptr)
        delete scoreArray;
}