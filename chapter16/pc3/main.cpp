#include "FunctionTemplates.h"
#include <iostream>
using namespace std;

int main()
{
    // Variables.
    int number1, number2;
    double num1, num2;

    // Prompt the user for two values.
    cout << "Enter the int value 1: ";
    cin >> number1;

    cout << "Enter the int value 2: ";
    cin >> number2;

    // Display the smaller and larger values between two values.
    cout << "The smaller value is " << minimum(number1, number2) << endl;
    cout << "The larger value is " << maximum(number1, number2) << endl;

    // Prompt the user for two double values.
    cout << "\nEnter the double value 1: ";
    cin >> num1;

    cout << "Enter the double value 2: ";
    cin >> num2;

    // Display the smaller and larger values between two values.
    cout << "The smaller value is " << minimum(num1, num2) << endl;
    cout << "The larger value is " << maximum(num1, num2) << endl;

    return 0;
}