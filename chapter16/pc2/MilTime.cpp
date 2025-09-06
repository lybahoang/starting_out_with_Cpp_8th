#include "MilTime.h"

// Constructor.
MilTime::MilTime(int hour, int second)
{
    // Try to set arguments to member variables
    // 'milHours' and 'milSeconds'.
    try
    {
        setTime(hour, second);
    }
    // If any exceptions are caught, then rethrows them.
    catch(BadHour)
    {
        throw;
    }
    catch(BadSeconds)
    {
        throw;
    }
}

// Function convertToStandardHour
void MilTime::convertToStandardHour()
{
    // Store the standard hours in the 'hour' variable.
    hour = (
        milHours / 100 > 12 ? 
        milHours / 100 - 12 :
        milHours / 100
    );
    
    // Store the standard minutes in the 'minute' variable.
    min = milHours % 100;

    // Store the milSecond in the 'sec' variable.
    sec = milSeconds;        
}

void MilTime::setTime(int newMilHours, int newSeconds)
{
    // If the newMilHours is larger than 2359 or 
    // less than 0, then throw a BadHour object
    // as an exception.
    if (newMilHours > 2359 || newMilHours < 0)
    {
        throw BadHour(newMilHours);
    }
    // If the newSeconds is larger than 59 or 
    // less than 0, then throw a BadMinutes object
    // as an exception.
    if (newSeconds > 59 || newSeconds < 0)
    {
        throw BadSeconds(newSeconds);
    }
    // Otherwise, store arguments in the member variables.
    milHours = newMilHours;
    milSeconds = newSeconds;
    
    // After that, convert to standard time and store in 
    // variables 'hours', 'min', and 'sec'.
    convertToStandardHour();
}