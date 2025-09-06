#include "Date.h"
#include <iostream>

// Function Date::setMonthValue
void Date::setMonthValue(int newMonth)
{
    // If newMonth is larger than 12 or less than 1,
    // then throw an InvalidMonth object with invalid
    // month value.
    if (newMonth > 12 || newMonth < 1)
        throw InvalidMonth(newMonth);
    // Otherwise, set 'newMonth' to 'month'.
    month = newMonth;
}

// Function Date::setDayValue
void Date::setDayValue(int newDay)
{
    // If newDay is larger than 31 or less than 1,
    // then throw an InvalidDay object with invalid
    // day value.
    if (newDay > 31 || newDay < 1)
        throw InvalidDay(newDay);
    // Otherwise, set 'newDay' to 'day'.
    day = newDay;
}

// Function Date::setYear
void Date::setYearValue(int newYear)
{
    year = newYear;
}

// Function Date::printSlashFormat
void Date::printSlashFormat() const
{
    cout << month << "/" << day << "/" << year << endl;
}

// Function Date::printMonthFirst
void Date::printMonthFirst() const
{
    const int SIZE = 12;        // Array size.
    const string monthNames[SIZE] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "Septempber", "October", "November",
        "December"
    };                          // Array of month names.

    // Print the date.
    cout << monthNames[month - 1] << " ";
    cout << day << ", ";
    cout << year << endl;
}

// Function Date::printDayFirst
void Date::printDayFirst() const
{
    const int SIZE = 12;        // Array size.
    const string monthNames[SIZE] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "Septempber", "October", "November",
        "December"
    };                          // Array of month names.

    // Print the date.
    cout << day << ", ";
    cout << monthNames[month - 1] << " ";
    cout << year << endl;
}