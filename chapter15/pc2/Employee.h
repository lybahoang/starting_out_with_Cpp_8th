#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
protected:
    string name;        // The name of the employee.
    string number;      // The number of the employee.
    string hireDate;    // The hire date of the employee.

public:
    // Constructors.
    Employee();
    Employee(const string &n, const string &num, const string &date);

    // Accessor functions.
    const string &getName() const;
    const string &getNumber() const;
    const string &getHireDate() const;

    // Mutator functions.
    void setName(const string &newName);
    void setNumber(const string &newNumber);
    void setHireDate(const string &newDate);

    // Virtual function.
    virtual void displayInfo() const;

    // Virtual destructor.
    virtual ~Employee() { };
};
#endif