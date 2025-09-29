#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Create an array of three Employee objects.
    Employee *employeeArray[3] = {
        new Employee("Susan meyers", 47899, "Accounting", "Vice President"),
        new Employee("Mark Jones", 39119, "IT", "Programmer"),
        new Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")
    };

    // Display the employee's data.
    for (int count = 0; count < 3; count++)
    {
        employeeArray[count]->displayInfo();
    }

    // Delete dynamically allocated memory.
    for (int count = 0; count < 3; count++)
    {
        delete employeeArray[count];
    }

    return 0;
}