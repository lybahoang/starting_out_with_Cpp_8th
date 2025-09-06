#include <iostream>
using namespace std;

// Function prototype.
template <class T>
T getAbsoluteValue(T value);

int main()
{
    // Variable declaration.
    int intValue;
    double doubleValue;

    // Promp user for an integer.
    cout << "Enter an integer value: ";
    cin >> intValue;

    // Display the absolute value of intValue.
    cout << "The absolute value of " << intValue << " is ";
    cout << getAbsoluteValue(intValue) << endl;

    // Promp user for an double.
    cout << "\nEnter an double value: ";
    cin >> doubleValue;

    // Display the absolute value of doubleValue.
    cout << "The absolute value of " << doubleValue << " is ";
    cout << getAbsoluteValue(doubleValue) << endl;

    return 0;
}

// Function getAbsoluteValue: to accept an argument and
// return its absolute value.
template <class T>
T getAbsoluteValue(T value)
{
    return (value < 0 ? -value : value);
}