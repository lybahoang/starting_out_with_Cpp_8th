#include <iostream>
using namespace std;

// Function prototype.
template <class T>
T total(int numOfValues);

int main()
{
    // Variable to hold the number of values.
    int numOfValues;

    // Prompt the user for the number of integer values.
    cout << "How many integer values do you want to enter? ";
    cin >> numOfValues;

    // Calculate the total and display it.
    int intTotal = total<int>(numOfValues);
    cout << "Total (int): " << intTotal << endl;

     // Prompt the user for the number of double values.
    cout << "\nHow many double values do you want to enter? ";
    cin >> numOfValues;

    // Calculate the total and display it.
    double doubleTotal = total<double>(numOfValues);
    cout << "Total (double): " << doubleTotal << endl;

    return 0;
}

/***
 * Function total: accepts an argument about the number
 * of values the function should read, and return
 * the total of numbers entered by the user.
 */
template <class T>
T total(int numOfValues)
{
    // The running total.
    T sum = 0;

    // Variable to hold the entered value.
    T value;

    // Prompt the user for values and add them
    // to the running total.
    for (int count = 0; count < numOfValues; count++)
    {
        cout << "Enter value #" << (count + 1) << ": ";
        cin >> value;
        sum = sum + value;
    }

    // Return the running total.
    return sum;
}