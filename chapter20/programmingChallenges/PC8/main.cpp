#include "BinaryTree.h"
#include "EmployeeInfo.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Create an array of EmployeeInfo objects.
    int EMPLOYEES = 8;
    EmployeeInfo *employeeArray[EMPLOYEES] = {
        new EmployeeInfo("John Williams", 1021),
        new EmployeeInfo("Bill Witherspoon", 1057),
        new EmployeeInfo("Jennifer Twain", 2487),
        new EmployeeInfo("Sophia Lancaster", 3769),
        new EmployeeInfo("Debbie Reece", 1017),
        new EmployeeInfo("George McMullen", 1275),
        new EmployeeInfo("Ashley Smith", 1899),
        new EmployeeInfo("Josh Plemmons", 4218)
    };

    // Create a BinaryTree object of EmployeeInfo type.
    BinaryTree<EmployeeInfo> employeeTree;

    // Insert EmployeeInfo objects in the array into the tree.
    for (int count = 0; count < EMPLOYEES; count++)
    {
        employeeTree.insertNode(*employeeArray[count]);
    }

    // Display each employee's information on the screen.
    employeeTree.displayInOrder();

    // Get an ID number from the user to search for the employee.
    int desiredID;

    cout << "Enter an ID number: ";
    cin >> desiredID;

    // Search for the employee in the tree.
    EmployeeInfo targetEmployee("",desiredID);
    const EmployeeInfo *searchedObject = employeeTree.search(targetEmployee);

    // Display the searching result.
    if (searchedObject == nullptr)
    {
        cout << "The employee is not found." << endl;
    }
    else
    {
        cout << searchedObject->getName() << endl;
    }

    // Delete dynamically allocated memormy for EmployeeInfo object.
    for (int count = 0; count < EMPLOYEES; count++)
    {
        delete employeeArray[count];
    }

    return 0;
}