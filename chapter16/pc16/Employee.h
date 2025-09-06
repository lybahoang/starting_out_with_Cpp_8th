#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
    string employeeName;        // The employee's name.
    int employeeNumber;      // The employee's number.
    string hireDate;            // The employee's hire date.

public:
    // Class exception.
    class InvalidEmployeeNumber
    {
    private:
        int invalidNumber;
    public:
        InvalidEmployeeNumber(int number)
            { invalidNumber = number; }
        int getInvalidNumber() const
            { return invalidNumber; }
    };

    // Default constructor.
    Employee()
        { employeeName = "";
          employeeNumber = 0;
          hireDate = ""; }
        
    // Constructor.
    Employee(const string &name, int number, const string &date);

    // Accessor functions.
    const string &getName() const
        { return employeeName; }

    int getNumber() const
        { return employeeNumber; }
    
    const string &getHireDate() const
        { return hireDate; }

    // Mutator functions.
    void setName(const string &name)
        { employeeName = name; }
    
    void setNumber(int number);

    void setHireDate(const string &date)
        { hireDate = date; }

    // Virtual function.
    virtual void displayInfo() const;

    // Destructor.
    virtual ~Employee() { };
};
#endif