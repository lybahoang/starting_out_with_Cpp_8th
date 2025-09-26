#include "ShiftSupervisor.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a ShiftSupervisor object.
    ShiftSupervisor supervisor1(
        "Ly Ba Hoang",  // Name.
        "259-H",        // Numbers.
        "27/01/2027",   // Hire date.
        250000,         // Annual salary.
        10000           // Annual bonus.
    );

    // Display the supervisor's information.
    supervisor1.displayInfo();

    return 0;
}