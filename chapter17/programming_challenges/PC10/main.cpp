#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Create a linked list to hold employee's IDs.
    LinkedList<unsigned long> empID;

    // Create a linked list to hold hours worked.
    LinkedList<double> hoursWorked;

    // Create a linked list to hold pay rate.
    LinkedList<double> payRates;

    // Create a linked list to hold wages.
    LinkedList<double> wages;

    // Variables.
    int numOfEmployees;     // The number of employees.

    // Prompt the user for the number of employees.
    cout << "Enter the number of employees: ";
    cin >> numOfEmployees;

    // Prompt the user for the employee information.
    cout << "Enter the employee IDs, hours worked, and pay rate.\n\n";
    for (int count = 0; count < numOfEmployees; count++)
    {
        unsigned long id;
        double hours, rate;

        cout << "Employee #" << (count + 1) << ".\n";

        // Prompt for employee's ID.
        cout << "   ID: ";
        cin >> id;

        // Prompt for employee's hours worked.
        do
        {
            cout << "   Hours worked: ";
            cin >> hours;
        } while (hours < 0);  

        // Prompt for employee's pay rate.
        do
        {
            cout << "   Pay rate: ";
            cin >> rate;
        } while (rate < 15.0);   

        // Append values to the lists.
        empID.appendNode(id);
        hoursWorked.appendNode(hours);
        payRates.appendNode(rate);

        // Calculate the gross wage for each employee.
        wages.appendNode(hours * rate);
    }

    // Display each employee’s identification number and gross wages. 
    cout << "\n---------------------------\n";
    cout << left << setw(12) << "ID" << setw(10) << "Gross wages ($)\n";
    cout << "---------------------------\n";
    for (int count = 0; count < numOfEmployees; count++)
    {
        cout << setw(12) << empID[count] << setw(10) << wages[count] << endl;
    }
    cout << "---------------------------\n";

    return 0;
}