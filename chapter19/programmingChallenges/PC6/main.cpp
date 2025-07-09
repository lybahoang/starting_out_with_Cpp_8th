#include <iostream>
using namespace std;

// Function prototypes.
int power(int, int);
void getBase(int &);
void getExponent(int &);

int main()
{
    int base, exponent;

    // Get the base.
    getBase(base);

    // Get the exponent.
    getExponent(exponent);

    // Calculate the power and display it.
    cout << base << " power " << exponent << " is " << power(base, exponent) << endl;

    return 0;
}

/**
 * Function power(int base, int exponent): Returns the base raised to the power
 * of exponent recursively.
 * @param base: The base (int).
 * @param exponent: The exponent (int).
 * @return: base raised to the power of exponent.
 */
int power(int base, int exponent)
{
    // Base case: If the exponent is equal to zero, then return 1.
    if (exponent == 0)
    {
        return 1;
    }
    // Recursive case: Returns base times to the power of base raised
    // to the power of exponent - 1.
    else
    {
        return base * power(base, exponent - 1);
    }
}

/**
 * Function getBase(int &): The function gets the base value for the power and
 * assigns it to the reference parameter.
 * @param base: The base of the power.
 * @return: void.
 */
void getBase(int &base)
{
    // Prompt the user for the base.
    cout << "Enter the base: ";
    cin >> base;
}

/**
 * Function getExponent(int &): The function gets the exponent value for the power and
 * assigns it to the reference parameter.
 * @param exponent: The base of the power.
 * @return: void.
 */
void getExponent(int &exponent)
{
    // Prompt the user for the exponent.
    cout << "Enter a nonnegative exponent: ";
    cin >> exponent;

    // Validate the exponent.
    while (exponent < 0)
    {
        cout << "Enter a valid expoenent: ";
        cin >> exponent;
    }
}