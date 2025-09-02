#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
using namespace std;

class NumDays
{
private:
    double workHours;   // The number of work hours.
    double workDays;    // The number of work days.
    void convertToDays();   // The function convert hours to days.

public:
    // Default constructor.
    NumDays();

    // Constructor.
    NumDays(const double &hours);

    // Mutator function.
    void setHours(const double &hours);

    // Accessor functions.
    double getHours() const;
    double getDays() const;

    // Overloaded operators.
    double operator+(const NumDays &);  // Overloaded addtition '+' operator.
    double operator-(const NumDays &);  // Overloaded subtraction '-' operator.
    NumDays operator++();               // Overloaded prefix increment '++' operator.
    NumDays operator++(int);            // Overloaded postfix increment '++' operator.
    NumDays operator--();               // Overloaded prefix increment '--' operator.
    NumDays operator--(int);            // Overloaded postfix increment '--' operator.

    // Friends
    friend ostream &operator<<(ostream &strm, const NumDays &);    // Overloaded cout operator.
    friend istream &operator>>(istream &strm, NumDays &);          // Overloaded cin opertor.
};
#endif