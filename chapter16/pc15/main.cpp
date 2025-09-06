#include <iostream>
#include <vector>
#include <algorithm>    // For binary_search.
using namespace std;

int main()
{
    // Variable to hold the user's input.
    int userAccNumber;

    // Create an object from the vector class.
    vector<int> validAccountNumbers {
        5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
        1005231, 6545231, 3852085, 7576651, 7881200, 1695172
    };

    // Prompt the user for an account number.
    cout << "Enter an account number: ";
    cin >> userAccNumber;

    // Sort the vector in ascending order before using
    // a binary search.
    sort(validAccountNumbers.begin(), validAccountNumbers.end());

    // Search for user's account number in the vector.
    if (binary_search(validAccountNumbers.begin(), validAccountNumbers.end(), userAccNumber))
        cout << "Your account number is valid.\n";
    else
        cout << "Your account number is invalid.\n";

    return 0;
}