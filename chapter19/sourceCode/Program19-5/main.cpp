// This program demonstrates a recursive function to calculate
// the greatest common divisor (gcd) of two numbers.
#include <iostream>
using namespace std;

// Function prototype.
int gcd(int, int);

int main()
{
    int num1, num2;

    // Get two numbers.
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Display the GCD of the numbers.
    cout << "The greatest common divisor of " << num1;
    cout << " and " << num2 << " is ";
    cout << gcd(num1, num2) << endl;

    return 0;
}

/**
 * Function gcd: uses recursion to calculate the greatest common
 * divisor of two integers.
 * @param x(int): the first integer.
 * @param y(int): the second integer.
 * @return: the greatest common divisor of x and y.
 */
int gcd(int x, int y)
{
    // Base case.
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}