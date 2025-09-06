#include "Employee.h"
#include "ProductionWorker.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Create two pointers to an Employee object.
    Employee *employee = new Employee;
    ProductionWorker *productionWorker = new ProductionWorker;

    try
    {
        // Initalize the employee object.
        employee->setName("Hoang");
        employee->setNumber(5172);
        employee->setHireDate("September 25, 2023");

        // Initialize the productionEmployee object.
        productionWorker->setName("Hiep");
        productionWorker->setNumber(3009);
        productionWorker->setHireDate("September 30, 2025");
        productionWorker->setShift(1);
        productionWorker->setPayRate(3500); 

        // Display the information of two workers.
        cout << "Worker #1.\n";
        employee->displayInfo();
    
        cout << "\nWorker #2.\n";
        productionWorker->displayInfo();
    }
    catch(ProductionWorker::InvalidEmployeeNumber e)
    {
        cout << "Error: " << e.getInvalidNumber();
        cout << " is an invalid employee number.\n";
    }
    catch(ProductionWorker::InvalidShift e)
    {
        cout << "Error: " << e.getInvalidShift();
        cout << " is an invalid shift.\n";
    }
    catch(ProductionWorker::InvalidPayRate e)
    {
        cout << "Error: " << e.getInvalidPayRate();
        cout << " is an invalid pay rate.\n";
    }
    

    return 0;
}