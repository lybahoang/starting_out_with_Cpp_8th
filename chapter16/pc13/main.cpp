/***
 * The program calculates and displays the total rainfall for
 * the year, the average monthly rainfall, and the months with
 * the highest and lowest amounts.
 * This version uses an STL vector instead of an array.
*/
#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void getRainfall(vector<double> &);
void processData(const vector<double> &);

// The main Function
int main()
{
    // Declare a vector of double that holds the 
    // rainfall data.
    vector<double> rainfallData;

    // Prompt for the rainfall of each month
    getRainfall(rainfallData);

    // Display results.
    processData(rainfallData);

    return 0;
}

/* Function getRainfall Definition
The function prompts for the rainfall amount of 12 months
*/
void getRainfall(vector<double> &rainfallVector)
{
    const int NUM_MONTH = 12;   // Constant for the number of months.
    double rainfall;            // Variable to hold rainfall data.

    for (int month = 1; month <= NUM_MONTH; month++)
    {
        // While the input is invalid, prompts again.
        do
        {
            cout << "Enter the rainfall amount of month " << month << ": ";
            cin >> rainfall;
            if (rainfall < 0)
            {
                cout << "Invalid value. Enter a positive value.\n\n";
            }
        } while (rainfall < 0);

        // Push the data back to the vector.
        rainfallVector.push_back(rainfall);
    }
}

/* Function processData Definition
The function calculates and displays the total rainfall for
the year, the average monthly rainfall, and the months with
the highest and lowest amounts.
*/
void processData(const vector<double> &rainfallVector)
{
    const int NUM_MONTH = 12;

    // Variable declaration
    double averageRainfall,
           lowest = rainfallVector[0],
           highest = rainfallVector[0];

    int lowestMonth = 1,
        highestMonth = 1;

    // Accumulator
    double totalRainfall = 0;

    for (int month = 1; month <= NUM_MONTH; month++)
    {
        totalRainfall += rainfallVector[month - 1];
        if (rainfallVector[month - 1] < lowest)
        {
            lowest = rainfallVector[month - 1];
            lowestMonth = month;
        }
        if (rainfallVector[month - 1] > highest)
        {
            highest = rainfallVector[month - 1];
            highestMonth = month;
        }
    }

    // Calculate the average rainfall
    averageRainfall = totalRainfall / NUM_MONTH;

    // Display results
    cout << "\nTotal rainfall: " << totalRainfall << endl;
    cout << "Average monthly rainfall: " << averageRainfall << endl;
    cout << "Month with the lowest rainfall: Month " << lowestMonth << " with " << lowest << endl;
    cout << "Month with the highest rainfall: Month " << highestMonth << " with " << highest << endl;
}
