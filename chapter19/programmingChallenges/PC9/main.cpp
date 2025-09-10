#include <iostream>
#include <string>
using namespace std;

void reverseString(const string &inputString)
{
    // Base case: If the string is empty, print nothing.
    if (inputString.length() == 0) return;

    // Display the last character in inputString.
    cout << inputString.back();

    // Recursive step: Display the reversed version of the substring
    // except the last element.
    reverseString(inputString.substr(0, inputString.length() - 1));
}

int main()
{
    // Create a string object.
    string name = "Ly Ba Hoang";

    // Display my name in reversed order.
    reverseString(name);

    return 0;
}