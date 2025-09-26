#include "ShiftSupervisor.h"
#include <iostream>
using namespace std;

/**
    The default constructor calls the default constructor of the
    base class and sets other memebers to default values.
 */
ShiftSupervisor::ShiftSupervisor() : Employee(), annualSalary(0.0), annualBonus(0.0)
{ }

/**
    The constructor sets values to member variables.
    @param name The supervisor's name.
    @param number The supervisor's number.
    @param date The supervisor's hire date.
    @param salary The supervisor's annual salary.
    @param bonus The supervisor's annual bonus.
 */
ShiftSupervisor::ShiftSupervisor(const string &name, const string &number,
const string &date, double salary, double bonus) : 
Employee(name, number, date), annualSalary(salary), annualBonus(bonus)
{ }

/**
    The getAnnualSalary function returns the supervisor's annual salary
    @return The value stored in the annualSalary variable.
 */
double ShiftSupervisor::getAnnualSalary() const
{
    return this->annualSalary;
}

/**
    The getAnnualBonus function returns the supervisor's annual bonus.
    @return The value stored in the annualBonus variable.
 */
double ShiftSupervisor::getAnnualBonus() const
{
    return this->annualBonus;
}

/**
    The setAnnualSalary function sets the supervisor's annual salary.
    @param salary The supervisor's annual salary.
 */
void ShiftSupervisor::setAnnualSalary(double salary)
{
    this->annualSalary = salary;
}

/**
    The setAnnualBonus function sets the supervisor's annual bonus.
    @param bonus The supervisor's annual bonus.
 */
void ShiftSupervisor::setAnnualBonus(double bonus)
{
    this->annualBonus = bonus;
}

/**
    The overriden displayInfo function displays the information of
    the supervisor to the scree.
 */
void ShiftSupervisor::displayInfo() const
{
    // Call the base class's displayInfo function.
    Employee::displayInfo();

    // Display the annual salary and annual bonus.
    cout << "Annual salary: $" << annualSalary << endl;
    cout << "Annual bonus: $" << annualBonus << endl;
}
