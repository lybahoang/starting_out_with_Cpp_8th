#include "Employee.h"
#include <iostream>
using namespace std;

/**
    The setName function sets the employee's name.
    @param newName The employee's name.
 */
void Employee::setName(const string &newName)
{
    this->name = newName;
}

/**
    The setIdNumber function sets the employee's id number.
    @param id The employee's id number.
 */
void Employee::setIdNumber(int id)
{
    this->idNumber = id;
}

/**
    The setDepartment function sets the employee's department.
    @param newDepartment The employee's department.
 */
void Employee::setDepartment(const string &newDepartment)
{
    this->department = newDepartment;
}

/**
    The setPosition function sets the employee's position.
    @param newPosition The employee's position.
 */
void Employee::setPosition(const string &newPosition)
{
    this->position = newPosition;
}

/**
    The displayInfo function displays the information of the
    employee on the screen.
 */
void Employee::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << idNumber << endl;
    cout << "Department: " << department << endl;
    cout << "Position: " << position << endl;
}