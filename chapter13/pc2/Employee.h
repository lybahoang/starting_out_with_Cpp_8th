#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
private:
    string name;        // The employee's name.
    int idNumber;       // The employee's ID number.
    string department;  // The employee's department.
    string position;    // The employee's position.

public:
    // Default constructor.
    Employee();

    // Constructors.
    Employee(const string &, int, const string &, const string &);
    Employee(const string &, int);

    // Accessor functions.
    const string &getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    const string &getDepartment() const { return department; }
    const string &getPosition() const { return position; }

    // Mutator functions.
    void setName(const string &);
    void setIdNumber(int);
    void setDepartment(const string &);
    void setPosition(const string &);

    // Other functions.
    void displayInfo() const;
};
#endif