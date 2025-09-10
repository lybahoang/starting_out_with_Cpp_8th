#include <iostream>
using namespace std;

// Function prototype.
int sumUpTo(int number)
{
    // The base case: If number is equal to 0, then returns 0.
    if (number == 0)
        return 0;
    // The recursive step: Returns sum of the number and the sum
    // up to (number - 1).
    return (number + sumUpTo(number - 1));
}

int main()
{
    // Display the sum up to 50.
    cout << "Sum up to 50: " << sumUpTo(50) << endl;

    // Display the sum up to 10.
    cout << "Sum up to 10: " << sumUpTo(10) << endl;

    // Display the sum up to 5.
    cout << "Sum up to 5: " << sumUpTo(5) << endl;
    
    return 0;
}