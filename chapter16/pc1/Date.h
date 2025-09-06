#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
public:
    // Exception classes.
    class InvalidDay
    {
    private:
        int invalidDay;
    public:
        InvalidDay(int d)
            { invalidDay = d; }
        int getInvalidDay() const
            { return invalidDay; }
    };

    class InvalidMonth
    {
    private:
        int invalidMonth;
    public:
        InvalidMonth(int m)
            { invalidMonth = m; }
        int getInvalidMonth() const
            { return invalidMonth; }
    };

    // Default constructor.
    Date()
        { month = day = year = 0; }

    // Constructor.
    Date(int m, int d, int y)
        { 
            month = m;
            day = d;
            year = y;
        }

    // Accessor functions.
    int getMonthValue() const
        { return month; }
    int getDayValue() const
        { return day; }
    int getYearValue() const
        { return year; }

    // Mutator functions.
    void setMonthValue(int);
    void setDayValue(int);
    void setYearValue(int);

    // Functions to display the date.
    void printSlashFormat() const;
    void printMonthFirst() const;
    void printDayFirst() const;
};
#endif