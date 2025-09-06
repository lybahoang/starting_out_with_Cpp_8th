#include "Time.h"
#include "MilTime.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a pointer an object from the MilTime class.
    MilTime *myTime = new MilTime();

    // Prompt the user for the military hours and seconds.
    int milHours, milSeconds;
    
    while (true)
    {
        try
        {
            cout << "Enter the military hours: ";
            cin >> milHours;
        
            cout << "Enter the military seconds: ";
            cin >> milSeconds;

            // Set the variables to the MilTime object.
            myTime->setTime(milHours, milSeconds);

            break;
        }
        catch(MilTime::BadHour badHour)
        {
            cout << "Error: " << badHour.getBadHour();
            cout << " is an invalid value for a military hour.\n";
        }
        catch(MilTime::BadSeconds badSecond)
        {
            cout << "Error: " << badSecond.getBadSeconds();
            cout << " is an invalid value for seconds.\n";
        }
    }

    // Display the military format.
    cout << "\nMilitary format.\n";
    cout << "Hours: " << myTime->getHour() << endl;
    cout << "Seconds: " << myTime->getSec() << endl;
    
    // Display the standard format.
    cout << "\nStandard format.\n";
    cout << "Hours: " << myTime->getStandHr() << endl;
    cout << "Minutes: " << myTime->getMin() << endl;
    cout << "Seconds: " << myTime->getSec() << endl;

    // Delete dynamically allocated memory.
    delete myTime;

    return 0;
}