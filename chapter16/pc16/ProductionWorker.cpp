#include "ProductionWorker.h"

// Constructor.
ProductionWorker::ProductionWorker(const string &name, int number, const string &date, int s, double rate)
: Employee(name, number, date)
{
    // Try to set the shift and the pay rate.
    try
    {
        setShift(s);
        setPayRate(rate);
    }
    // Handles exception when the shift is invalid.
    catch(const InvalidShift e)
    {
        throw;
    }
    // Handles exception when the pay rate is invalid.
    catch(const InvalidPayRate e)
    {
        throw;
    }
    // Handles exception when the employee's number is invalid.
    catch(const InvalidEmployeeNumber e)
    {
        throw;
    }
}

/***
 * Function setShift: The function accepts an integer about the shift.
 * It then checks if the shift is valid (1 or 2). If it is invalid, then
 * the function throw an InvalidShift object as an exception.
 */
void ProductionWorker::setShift(int newShift)
{
    // If 'newShift' is not 1 and 2, then throw
    // an InvalidShift object as an exception.
    if (newShift != 1 && newShift != 2)
        throw InvalidShift(newShift);
    // Otherwise, store the argument in 'shift'.
    shift = newShift;
}


/***
 * Function setPayRate: The function accepts an double about the pay rate.
 * It then checks if the payrate is valid (nonnegative). If it is invalid, 
 * then the function throw an InvalidPayRate object as an exception.
 */
void ProductionWorker::setPayRate(int rate)
{
    // If 'rate' is negative, then throw
    // an InvalidPayRate object as an exception.
    if (rate < 0)
        throw InvalidPayRate(rate);
    // Otherwise, store the argument in 'hourlyPayRate'.
    hourlyPayRate = rate;
}

/***
 * Function displayInfo: The function prints all information
 * of the employee to the screen.
 */
void ProductionWorker::displayInfo() const
{
    cout << "Name: " << employeeName << endl;
    cout << "Number: " << employeeNumber << endl;
    cout << "Hire date: " << hireDate << endl;
    cout << "Shfit: " << (shift == 1 ? "Day" : "Night") << endl;
    cout << "Pay rate: " << hourlyPayRate << endl;
}