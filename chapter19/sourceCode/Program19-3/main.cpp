// This program demonstrates a recursive function to
// calculate the factorial of a number.
#include <iostream>
using namespace std;

// Function prototype.
int factorial(int);

int main()
{
    int number;
    
    // Get a number from the user.
    cout << "Enter an integer value and I will display\n";
    cout << "its factorial: ";
    cin >> number;

    // Display the factorial of the number.
    cout << "The factorial of " << number << " is ";
    cout << factorial(number) << endl;

    return 0;
}

/**
 * Function factorial(int): A recursive function to calculate
 * the factorial of an integer.
 * @param n: The parameter to calculate the factorial.
 * @return the factorial of n.
 */
int factorial(int n)
{
    // Base case: If n is equal to 0, then the factorial of n
    // is equal to 1.
    if (n == 0)
        return 1;
    // Recursive case.
    return n * factorial(n - 1);
}