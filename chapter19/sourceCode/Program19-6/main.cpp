// This program demonstrates a recursive function
// that calculates Fiboncci numbers.
#include <iostream>
using namespace std;

// Function prototype.
int fib(int);

int main()
{
    cout << "The first 10 Fibonacci numbers are:\n";
    for (int x = 0; x < 10; x++)
        cout << fib(x) << " ";
    cout << endl;

    return 0;
}


/**
 * Function fib(int): Accepts an int argument in n.
 * This function returns the nth Fibonacci number.
 */
int fib(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}