#include "Date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * Default constructor: The function assigns default values to member variables.
 */
Date::Date()
{
    month = 1;
    day = 1;
    year = 1945;
}

/**
 * Constructor: The constructor accepts arguments about the month, day, and year and
 * then assigns it to the corresponding member variables by calling mutator functions.
 * @param m (int): The month of the date.
 * @param d (int): The day of the date.
 * @param y (int): The year of the date.
 */
Date::Date(int m, int d, int y)
{
    setMonth(m);
    setDay(d);
    setYear(y);
}

/**
 * Function setMonth. The function accepts an argument about the month of the date. It
 * then validates if the value of the month is valid. If it is valid, the argument is
 * assigned to the corresponding member variable.
 * @param m (int): The month of the date.
 */
void Date::setMonth(int m)
{
    // If the value of the argument is not from 1 to 12, then displays an error message
    // and terminate the program.
    if (m > 12 || m < 1)
    {
        cout << "Error: Invalid month value.";
        exit(EXIT_FAILURE);
    }
    // Otherwise, store the argument to the member variable.
    month = m;
}

/**
 * Function setDay. The function accepts an argument about the day of the date. It
 * then validates if the value of the day is valid. If it is valid, the argument is
 * assigned to the corresponding member variable.
 * @param d (int): The day of the date.
 */
void Date::setDay(int d)
{
    // If the value of the argument is not from 1 to 31, then displays an error message
    // and terminate the program.
    if (d > 31 || d < 1)
    {
        cout << "Error: Invalid day value.";
        exit(EXIT_FAILURE);
    }
    // Otherwise, store the argument to the member variable.
    day = d;
}

/**
 * Function setYear. The function accepts an argument about the year of the date. It
 * then validates if the value of the year is valid. If it is valid, the argument is
 * assigned to the corresponding member variable.
 * @param y (int): The year of the date.
 */
void Date::setYear(int y)
{
    // If the value of the argument is negative then displays an error message
    // and terminate the program.
    if (y < 0)
    {
        cout << "Error: Invalid year value.";
        exit(EXIT_FAILURE);
    }
    // Otherwise, store the argument to the member variable.
    year = y;
}

/**
 * Function displayFormat1. The function displays the date to the screen under
 * the format similar to 09/25/2005.
 */
void Date::displayFormat1() const
{
    cout << (month < 10 ? 0 : "") << month << "/";
    cout << (day < 10 ? 0 : "") << day << "/";
    cout << year;
}