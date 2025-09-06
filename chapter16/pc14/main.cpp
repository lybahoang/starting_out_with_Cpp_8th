#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function prototypes.
void sortVector(vector<double> &);
double calculateAverage(vector<double>);

int main()
{
    int numOfScores;    // The number of test scores.
    double score;       // The test score.

    // Create an object from the vector class.
    vector<double> myScores;

    // Prompt the user for the number of test scores.
    cout << "Enter the number of test scores: ";
    cin >> numOfScores;

    // Prompt the user for the test scores.
    for (int count = 0; count < numOfScores; count++)
    {
        // While 'score' is negative, prompts again.
        do
        {
            cout << "Enter test score #" << (count + 1) << ": ";
            cin >> score;
            if (score < 0)
                cout << "Error: Invalid value. Enter again.\n";
        } while (score < 0);
        // Push the score into the vector.
        myScores.push_back(score);
    }

    // Sort and display the sorted list.
    cout << "\nSorting the list...\n";
    sortVector(myScores);
    cout << "Here are the sorted list.\n";
    for (int count = 0; count < myScores.size(); count++)
        cout << myScores[count] << " ";

    // Display the average score.
    cout << "\nAverage score: " << calculateAverage(myScores) << endl;

    return 0;
}

/***
 * Function sortVector: The function sorts the vector in 
 * ascending order.
 */
void sortVector(vector<double> &theVector)
{
    sort(theVector.begin(), theVector.end());
}

/***
 * Function calculateAverage: The function accepts a vector
 * and returns the average of elements in it.
 */
double calculateAverage(vector<double> theVector)
{
    double total = 0;    // An accumulator.

    // Define an iterator object.
    vector<double>::iterator iter;

    // Calculate the total score.
    for (iter = theVector.begin(); iter < theVector.end(); iter++)
        total += *iter;

    // Return the average score.
    return (total / theVector.size());
}