#include "NumDays.h"
#include <iostream>
using namespace std;

int main()
{
    // Declare one NumDays object constructor.
    NumDays *dayOnePtr = new NumDays(11);

    // Declare one NumDays object with cin >> operator.
    NumDays *dayTwoPtr = new NumDays;
    cout << "Day #2: ";
    cin >> *dayTwoPtr;

    // Adding the two objects.
    cout << "\nAdding the two objects..." << endl;
    cout << "Sum of hours: " << (*dayOnePtr) + (*dayTwoPtr) << endl;

    // Subtracting the two objects.
    cout << "\nSubtracting the two objects..." << endl;
    cout << "Difference of hours: " << (*dayOnePtr) - (*dayTwoPtr) << endl;

    // Prefix increment the object 1.
    cout << "\nPrefix increment object 1..." << endl;
    cout << ++(*dayOnePtr) << endl;

    // Postfix increment the object 2.
    cout << "\nPostfix increment object 2..." << endl;
    cout << (*dayTwoPtr)++ << endl;
    cout << *dayTwoPtr << endl;

    // Prefix decrement the object 1.
    cout << "\nPrefix decrement object 1..." << endl;
    cout << --(*dayOnePtr) << endl;

    // Postfix decrement the object 2.
    cout << "\nPostfix decrement object 2..." << endl;
    cout << (*dayTwoPtr)-- << endl;
    cout << *dayTwoPtr << endl;

    return 0;
}