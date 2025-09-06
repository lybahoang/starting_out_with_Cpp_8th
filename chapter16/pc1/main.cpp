#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    // Variable.
    int newDay, newMonth;

    // Create an object from the Date class.
    Date my_date(9, 25, 2025);

    // Display the date in month first format.
    my_date.printMonthFirst();

    // Try to change the day and month values.
    try
    {
        // Prompt the user for new values.
        cout << "\nEnter a new day: ";
        cin >> newDay;
        cout << "Enter a new month: ";
        cin >> newMonth;

        // Set new day to the date.
        my_date.setDayValue(newDay);

        // Set new month to the date.
        my_date.setMonthValue(newMonth);

        // Display the date.
        my_date.printMonthFirst();
    }
    catch(Date::InvalidDay e)
    {
        cout << "ERROR: " << e.getInvalidDay();
        cout << " is an invalid value for day.\n";
    }
    catch(Date::InvalidMonth e)
    {
        cout << "ERROR: " << e.getInvalidMonth();
        cout << " is an invalid value for month.\n";
    }
    
    return 0;
}