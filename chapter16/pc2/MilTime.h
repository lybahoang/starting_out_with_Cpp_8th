#ifndef MIL_TIME_H
#define MIL_TIME_H
#include "Time.h"

class MilTime : public Time
{
protected:
    int milHours;
    int milSeconds;
    void convertToStandardHour();
public:
    // Exception classes.
    class BadHour
    {
    private:
        int value;
    public:
        BadHour(int v)
            { value = v; }
        int getBadHour() const
            { return value; }
    };

    class BadSeconds
    {
    private:
        int value;
    public:
        BadSeconds(int s)
            { value = s; }
        int getBadSeconds() const
            { return value; }
    };
    
    // Default constructor.
    MilTime() : Time()
        { milHours = 0; milSeconds = 0; }

    // Constructor.
    MilTime(int hour, int second);

    // Accessor functions.
    virtual int getHour() const
        { return milHours; }
    
    int getStandHr() const
        { return hour; }
    
    // Mutator functions.
    void setTime(int newMilHours, int newSeconds);
};

#endif