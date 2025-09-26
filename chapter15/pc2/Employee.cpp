#include "Employee.h"
#include <iostream>

// Constants for default values.
const string DEFAULT_NAME = "No name";
const string DEFAULT_NUMBER = "blank";
const string DEFAULT_DATE = "blank";

/**
 * Default constructor. The constructor assigns default values to member variables.
 */
Employee::Employee() : name(DEFAULT_NAME), number(DEFAULT_NUMBER), hireDate(DEFAULT_DATE)
{ }

/**
    Constructor. The constructor accepts arguments for the employee's name, number, and hire date and then assigns them to appropriate member variables.
    @param n The employee's name.
    @param num The employee's number.
    @param date The mployee's hire date.
 */
Employee::Employee(const string &n, const string &num, const string &date) :
name(n), number(num), hireDate(date)
{ }

/**
 * Function getName. The function returns the employee name.
 * @param none.
 * @return string - Employee name.
 */
const string &Employee::getName() const { return name; }

/**
 * Function getNumber. The function returns the employee number.
 * @param none.
 * @return string - Employee number.
 */
const string &Employee::getNumber() const { return number; }

/**
 * Function getHireDate. The function returns the employee hire date.
 * @param none.
 * @return string - Employee hire date.
 */
const string &Employee::getHireDate() const { return hireDate; }

/**
 * Function setName. The function accepts an argument about the employee name and assings it
 * to the 'name' member variables.
 * @param newName (string) The employee name.
 * @return void
 */
void Employee::setName(const string &newName)
{
    name = newName;
}

/**
 * Function setNumber. The function accepts an argument about the employee number and assings it
 * to the 'number' member variables.
 * @param newNumber (string) The employee number.
 * @return void
 */
void Employee::setNumber(const string &newNumber)
{
    number = newNumber;
}

/**
 * Function setHireDate. The function accepts an argument about the employee hire date and assings it
 * to the 'hireDate' member variables.
 * @param newDate (string) The employee hire date.
 * @return void
 */
void Employee::setHireDate(const string &newDate)
{
    hireDate = newDate;
}

/**
 * Function displayInfo. The function displays the information of the employee to the screen.
 */
void Employee::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Number: " << number << endl;
    cout << "Hire date: " << hireDate << endl;
}