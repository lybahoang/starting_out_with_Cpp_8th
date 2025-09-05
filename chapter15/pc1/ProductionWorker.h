#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H

#include "Employee.h"

class ProductionWorker : public Employee
{
protected:
    int shift;              // The shift of the employee.
    double hourlyPayRate;   // The hourly pay rate of the employee.

public:
    // Constructors.
    ProductionWorker();
    ProductionWorker(const string &n, const string &num, const string &date,
    int s, double rate);

    // Accessor functions.
    int getShift() const;
    double getHourlyPayRate() const;

    // Mutator functions.
    void setShift(int newShift);
    void setHourlyPayRate(double newRate);

    // Overriden functions.
    virtual void displayInfo() const override;

    // Default destructor.
    virtual ~ProductionWorker() { };
};
#endif