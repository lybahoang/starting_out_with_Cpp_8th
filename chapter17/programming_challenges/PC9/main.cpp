#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    const int MONTHS = 12;  // The number of months.
    double rainfall;        // To hold the rainfall value.

    // Create LinkedList object to hold monthly data.
    LinkedList<double> rainfallData;

    // Prompt the user for data of rainfall.
    cout << "Enter data for monthly rainfall.\n";
    for (int count = 0; count < MONTHS; count++)
    {
        cout << "Enter data for month #" << (count + 1) << ": ";
        cin >> rainfall;

        // While the input is negative, then prompt again.
        while (rainfall < 0)
        {
            cout << "Error: Invalid value.\n";
            cout << "Enter data for month #" << (count + 1) << ": ";
            cin >> rainfall;
        }

        // Otherwise, append the data to the list.
        rainfallData.appendNode(rainfall);
    }

    return 0;
}