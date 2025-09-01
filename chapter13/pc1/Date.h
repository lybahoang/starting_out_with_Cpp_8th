#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int month;
    int day;
    int year;

public:
    // Default constructor.
    Date();

    // Constructor.
    Date(int m, int d, int y);

    // Mutator functions.
    void setMonth(int);
    void setDay(int);
    void setYear(int);

    // Accessor functions.
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Other functions.
    void displayFormat1() const;
    void displayFormat2() const;
    void displayFormat3() const;
};
#endif