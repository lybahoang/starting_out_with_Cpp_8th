#include "NumDays.h"
#include <cstdlib>

// Constants for default values and ratio.
const double DEFAULT_HOURS = 0;
const int HOURS_A_DAY = 8;

/**
 * Function convertToDays. The function converts hours into days with the ratio of 8 hours = 1 days. 
 */
void NumDays::convertToDays()
{
    workDays = workHours / HOURS_A_DAY;
}

/**
 * Default constructor. The default constructor assigns default values to hours and calls the function 
 * convertToDays to convert the hours into days.
 */
NumDays::NumDays() 
{
    workHours = DEFAULT_HOURS;
    convertToDays();
}

/**
 * Constructor. The constructor accepts an argument about the hours and then converts it into the corresponding
 * number of days. The constructor calls the function setHours to perform this work.
 * @param hours (double): The number of hours.
 */
NumDays::NumDays(const double &hours)
{
    setHours(hours);
}

/**
 * Function setHours. The function accepts an argument about the hours, assigns it to the member variable, and the
 * converts the hours into days. The function also perform input validation. If the value of the argument is negative
 * then the function terminates the program.
 * @param hours (double): The number of hours.
 */
void NumDays::setHours(const double &hours)
{
    // If the value of the argument is negative, then terminates the program.
    if (hours < 0)
    {
        cout << "Error. Invalid value for hours.";
        exit(EXIT_FAILURE);
    }
    // Otherwise, stores the argument to workHours.
    workHours = hours;
    // Convert to days.
    convertToDays();
}

/**
 * Function getHours. The function returns the values in the variable 'workHours'.
 */
double NumDays::getHours() const { return workHours; }

/**
 * Function getDays. The function returns the values in the variable 'workDays'.
 */
double NumDays::getDays() const { return workDays; }

/**
 * Overloaded addition + operator: The operator adds two NumDays objects together by adding the two objects' hours
 * and then returns that sum.
 * @param obj (NumDays): The object on the right side of the operator.
 * @return The sum of the two objects' hours.
 */
double NumDays::operator+(const NumDays &obj)
{
    return (this->workHours + obj.workHours);
}

/**
 * Overloaded subtraction - operator: The operator subtracts two NumDays objects together by subtracting the two objects'
 * hours and then returns that difference.
 * @param obj (NumDays): The object on the right side of the operator.
 * @return The differnce of the two objects' hours.
 */
double NumDays::operator-(const NumDays &obj)
{
    return (this->workHours - obj.workHours);
}

/**
 * Prefix increment ++ operator: The operator increments the number of hours and recalculates the number of days
 * in the object.
 * @param void.
 * @return The NumDays object after being incremented.
 */
NumDays NumDays::operator++()
{
    // Increment the number of hours stored in this object.
    this->workHours = this->workHours + 1;

    // Update the number of days stored in this object.
    this->convertToDays();

    // Return this object.
    return *this;
}

/**
 * Postfix increment ++ operator: The operator increments the number of hours and recalculates the number of days
 * in the object.
 * @param void.
 * @return The NumDays object, which is not incremented.
 */
NumDays NumDays::operator++(int)
{
    // Create another NumDays object to store the values before incrementing.
    NumDays temp(this->workHours);

    // Increment the number of hours stored in this object.
    this->workHours = this->workHours + 1;

    // Update the number of days stored in this object.
    this->convertToDays();

    // Return the temp object..
    return temp;
}

/**
 * Prefix decrement -- operator: The operator decrements the number of hours and recalculates the number of days
 * in the object.
 * @param void.
 * @return The NumDays object after being decremented.
 */
NumDays NumDays::operator--()
{
    // Decrement the number of hours stored in this object.
    this->workHours = this->workHours - 1;

    // Update the number of days stored in this object.
    this->convertToDays();

    // Return this object.
    return *this;
}

/**
 * Postfix decrement -- operator: The operator decrements the number of hours and recalculates the number of days
 * in the object.
 * @param void.
 * @return The NumDays object, which is not decremented.
 */
NumDays NumDays::operator--(int)
{
    // Create another NumDays object to store the values before incrementing.
    NumDays temp(this->workHours);

    // Increment the number of hours stored in this object.
    this->workHours = this->workHours - 1;

    // Update the number of days stored in this object.
    this->convertToDays();

    // Return the temp object..
    return temp;
}

/**
 * Friend operator<<: The operator displays the number of hours and days stored in the object to the screen.
 * @param strm (ostream): The stream object on the left side of the stream insertion operator (<<).
 * @param obj (NumDays): The object on the right side of the operator.
 * @return A reference to strm.
 */
ostream &operator<<(ostream &strm, const NumDays &obj)
{
    strm << "Number of Hours: " << obj.workHours << endl;
    strm << "Number of Days: " << obj.workDays << endl;
    return strm;
}
      
/**
 * Friend operator>>: The operator gets input of the number of hours.
 * @param strm (sstream): The stream object on the left side of the stream extraction operator (>>).
 * @param obj (NumDays): The object on the right side of the operator.
 * @return A reference to strm.
 */
istream &operator>>(istream &strm, NumDays &obj)
{
    // Variable to keep the input.
    double hours;

    // Prompt the user for the number of hours.
    strm >> hours;

    // Set the input to the object.
    obj.setHours(hours);

    return strm;
}