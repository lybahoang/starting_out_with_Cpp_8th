#include "ProductionWorker.h"
#include <iostream>
using namespace std;

// Constant for default values.
const int DEFAULT_SHIFT = 0;
const double DEFAULT_PAY_RATE = 0.0;

// Constant for employee shift.
const int DAY_SHIFT = 1;
const int NIGHT_SHIFT = 2;

/**
 * Default constructor. The constructor assigns default values to member variables. The constructor
 * also calls the default constructor of the base class 'Employee'.
 */
ProductionWorker::ProductionWorker() : Employee()
{
    shift = DEFAULT_SHIFT;
    hourlyPayRate = DEFAULT_PAY_RATE;
}

/**
 * Constructor. The constructor accepts arguments about the name, number, hire date, shift, and the 
 * hourly pay rate of the employee and assigns them to appropriate member variables.
 * @param n (string): Employee name.
 * @param num (string): Employee number.
 * @param date (string): Employee hire date.
 * @param s (int): Shift.
 * @param rate (double): Hourly pay rate.
 */
ProductionWorker::ProductionWorker(const string &n, const string &num, const string &date,
    int s, double rate) : Employee(n, num, date)
{
    shift = s;
    hourlyPayRate = rate;
}

/**
 * Function getShift. The function returns the value representing the shift of the employee.
 * @param none.
 * @return 1 for day shift or 2 for night shift.
 */
int ProductionWorker::getShift() const { return shift; }

/**
 * Function getHourlyPayRate. The function returns the value representing the hourly pay rate of 
 * the employee.
 * @param none.
 * @return Hourly pay rate.
 */
double ProductionWorker::getHourlyPayRate() const { return hourlyPayRate; }

/**
 * Function setShift. The function accepts an arugment about the shift of the employee and assigns
 * it to the 'shift' member variable.
 * @param newShift (int) The shift of the employee.
 * @return void.
 */
void ProductionWorker::setShift(int newShift)
{
    shift = newShift;
}

/**
 * Function setHourlyPayRate. The function accepts an arugment about the hourly pay rate of the
 * employee and assigns it to the 'hourlyPayRate' member variable.
 * @param newRate (double) The hourly pay rate of the employee.
 * @return void.
 */
void ProductionWorker::setHourlyPayRate(double newRate)
{
    hourlyPayRate = newRate;
}

/**
 * Function displayInfor. The function displays the information of the employee to the screen.
 */
void ProductionWorker::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Number: " << number << endl;
    cout << "Hire date: " << hireDate << endl;
    cout << "Shift: ";
    cout << (shift == 1 ? "Day" : "Night") << endl;
    cout << "Hourly pay rate: $" << hourlyPayRate << endl;
}