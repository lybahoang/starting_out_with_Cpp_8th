// This program demonstrates an iterative method to calculate the factorial.
#include <iostream>
using namespace std;

// Function prototype.
int factorial(int);

int main()
{
    int num;

    // Get a number from the user.
    cout << "Enter a number: ";
    cin >> num;

    // Display the factorial of num.
    cout << "Factorial of the number is "
         << factorial(num) << endl;

    return 0;
}

/**
 * Function factorial: calculates the factorial of a number.
 * @param num: The number to calculate the factorial.
 * @return: The factorial of num.
 */
int factorial(int num)
{
    int result = 1;     // To hold the calculation.

    for (int count = 1; count <= num; count++)
    {
        result = result * count;
    }

    return result;
}