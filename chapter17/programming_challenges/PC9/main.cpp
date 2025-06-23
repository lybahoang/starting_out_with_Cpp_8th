#include "LinkedList.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int months = 12;        // The number of months.
    double rainfall;        // To hold the rainfall value.

    // Create LinkedList object to hold monthly data.
    LinkedList<double> rainfallData;

    // Prompt the user for the number of months of data.
    cout << "How many months of data? ";
    cin >> months;

    // Prompt the user for data of rainfall.
    cout << "Enter data for monthly rainfall.\n";
    for (int count = 0; count < months; count++)
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

    // Display the data.
    cout << "\nHere are the data of rainfall.\n";
    rainfallData.display();
    cout << endl;

    return 0;
}