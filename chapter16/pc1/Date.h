#ifndef DATE_H
#define DATE_H

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
        int day;
    public:
        InvalidDay(int d)
            { day = d; }
        int getDay() const
            { return day; }
    };

    class InvalidMonth
    {
    private:
        int month;
    public:
        InvalidMonth(int m)
            { month = m; }
        int getMonth() const
            { return month; }
    };
    
    // Default constructor.
    Date();

    // Constructor.
    Date(int m, int d, int y);

    // Mutator functions.
    void setMonth(int);
    void setDay(int);
    void setYear(int);

    // Accessor functions.
    int getMonth() const
        { return month; }
    int getDay() const
        { return day; }
    int getYear() const
        { return year; }

    // Other functions.
    void displayFormat1() const;
    void displayFormat2() const;
    void displayFormat3() const;
};
#endif