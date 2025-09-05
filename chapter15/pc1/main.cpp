#include "ProductionWorker.h"
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Create two objects of Employee and ProductionWorker.
    Employee *employee1 = new Employee("Ly Ba Hoang", "1695172", "25 September 2027");
    Employee *employee2 = new ProductionWorker("Jack", "32903", "05 September 2005", 1, 25.5);

    // Display the information of employee1.
    cout << "Employee #1" << endl;
    employee1->displayInfo();

    // Display the information of employee2.
    cout << "\nEmployee #2" << endl;
    employee2->displayInfo();

    return 0;
}