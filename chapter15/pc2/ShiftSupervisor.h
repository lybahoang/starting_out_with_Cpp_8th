#ifndef SHIFT_SUPERVISOR_H
#define SHIFT_SUPERVISOR_H

#include "Employee.h"

class ShiftSupervisor : public Employee
{
protected:
    double annualSalary;    // The shift supervisor's annual salary.
    double annualBonus;     // The shift supervisor's annual bonus.

public:
    // Constructors.
    ShiftSupervisor();
    ShiftSupervisor(const string &, const string &, const string &,
    double, double);

    // Accessor functions.
    double getAnnualSalary() const;
    double getAnnualBonus() const;

    // Mutator functions.
    void setAnnualSalary(double);
    void setAnnualBonus(double);

    // Overriden virtual function.
    virtual void displayInfo() const override;

    // Destructor.
    virtual ~ShiftSupervisor() { };
};
#endif