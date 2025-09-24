/**
    The EmployeeInfo class holds information of an employee including
    the employee's name and identification number.
 */
#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H

#include <iostream>
#include <string>
using namespace std;

class EmployeeInfo
{
private:
    string name;    // The employee's name.
    int idNumber;   // The employee's id number.

public:
    // Constructors.
    EmployeeInfo();
    EmployeeInfo(const string &, int);
    EmployeeInfo(const EmployeeInfo &);

    // Accessor functions.
    string getName() const;
    int getIdNumber() const;

    // Mutator functions.
    void setName(const string &);
    void setIdNumber(int);

    // Overloaded operators.
    bool operator < (const EmployeeInfo &) const;
    bool operator > (const EmployeeInfo &) const;
    bool operator == (const EmployeeInfo &) const;
    EmployeeInfo &operator = (const EmployeeInfo &);
    
    // Friends.
    friend ostream &operator << (ostream &, const EmployeeInfo &);
};
#endif