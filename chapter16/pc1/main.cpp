#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    int month;      // To hold a month.
    int day;        // To hold a day.
    int year;       // To hold a year.
    bool tryAgain;  // A flag to reread data.

    // Create a Date object.
    Date today;
    today.setYear(2025);

    // Get the month from the user.
    cout << "Enter the month: ";
    cin >> month;

    // Store the month in the today object.
    tryAgain = true;
    while (tryAgain)
    {
        try
        {
            today.setMonth(month);
            // If no exception was thrown, then the next statement will execute.
            tryAgain = false;
        }
        catch (Date::InvalidMonth m)
        {
            cout << "Error: " << m.getMonth() << " is an invalid month.\n";
            cout << "Enter another month: ";
            cin >> month;
        }
    }

    // Get the day from the user.
    cout << "Enter the day (1-31): ";
    cin >> day;

    // Store the day in the today object.
    tryAgain = true;
    while (tryAgain)
    {
        try
        {
            today.setDay(day);
            // If no exception was thrown, then the next statement will execute.
            tryAgain = false;
        }
        catch (Date::InvalidDay d)
        {
            cout << "Error: " << d.getDay() << " is an invalid day.\n";
            cout << "Enter another day (1-31): ";
            cin >> day;
        }
    }

    // Display the date in three formats.
    today.displayFormat1();
    cout << endl;
    today.displayFormat2();
    cout << endl;
    today.displayFormat3();
    cout << endl;

    return 0;
}