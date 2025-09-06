#include "Employee.h"

// Constructor.
Employee::Employee(const string &name, int number, const string &date)
{
    // Try to assigns arguments to the member variables.
    try
    {
        setName(name);
        setNumber(number);
        setHireDate(date);
    }
    // Handles exception raised by an invalid employee's number.
    catch(const InvalidEmployeeNumber e)
    {
        throw;
    }
}

/***
 * Function setNumber: The function accepts an argument and
 * assigns it to 'employeeNumber'. If the argument is less than
 * 0 or greater than 9999, it throws an exception.
 */
void Employee::setNumber(int number)
{
    // If 'number' is less than 0 or greater than 9999,
    // then throw an object of the class InvalidEmployeeNumber
    // as an exception.
    if (number < 0 || number > 9999)
        throw InvalidEmployeeNumber(number);
    // Otherwise, store the argument in 'employeeNumber'.
    employeeNumber = number;
}

/***
 * Function displayInfo: The function prints all information
 * of the employee to the screen.
 */
void Employee::displayInfo() const
{
    cout << "Name: " << employeeName << endl;
    cout << "Number: " << employeeNumber << endl;
    cout << "Hire date: " << hireDate << endl;
}