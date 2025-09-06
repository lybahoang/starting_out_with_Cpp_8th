#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H
#include "Employee.h"

class ProductionWorker : public Employee
{
protected:
    int shift;
    double hourlyPayRate;

public:
    // Exception classes.
    class InvalidShift
    {
    private:
        int invalidShift;
    public:
        InvalidShift(int shift)
            { invalidShift = shift; }
        int getInvalidShift() const
            { return invalidShift; }
    };

    class InvalidPayRate
    {
    private:
        double invalidPayRate;
    public:
        InvalidPayRate(double rate)
            { invalidPayRate = rate; }
        double getInvalidPayRate() const
            { return invalidPayRate; }
    };

    // Default constructor.
    ProductionWorker() : Employee()
        { shift = 0; hourlyPayRate = 0.0; }

    // Constructor.
    ProductionWorker(const string &name, int number, const string &date, int s, double rate);

    // Accessor functions.
    int getShift() const
        { return shift; }
    
    double getPayRate() const
        { return hourlyPayRate; }
    
    // Mutator functions.
    void setShift(int newShift);
    void setPayRate(int rate);

    // Overridden functions.
    virtual void displayInfo() const override;

    // Destructor.
    virtual ~ProductionWorker() { };    
};
#endif