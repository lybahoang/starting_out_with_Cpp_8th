#include "EmployeeInfo.h"

/**
    The default constructor creates an empty object.
 */
EmployeeInfo::EmployeeInfo()
{
    name = "";
    idNumber = 0;
}

/**
    The constructor sets the name and id of the employee.
    @param employeeName The employee's name.
    @param id The employee's id.
 */
EmployeeInfo::EmployeeInfo(const string &employeeName, int id)
{
    name = employeeName;
    idNumber = id;
}

/**
    The copy constructor makes a copy of the other object into
    this object.
    @param other The other object to be copied.
 */
EmployeeInfo::EmployeeInfo(const EmployeeInfo &other)
{
    // Copy the employee's name.
    this->name = other.name;

    // Copy the employee's id number.
    this->idNumber = other.idNumber;
}

/**
    The getName function returns the employee's name.
    @return The value stored in the name variable.
 */
string EmployeeInfo::getName() const
{
    return name;
}

/**
    The getIdNumber function returns the employee's id number.
    @return The value stored in the idNumber variable.
 */
int EmployeeInfo::getIdNumber() const
{
    return idNumber;
}

/**
    The setName function sets the employee's name.
    @param newName The new name of the employee.
 */
void EmployeeInfo::setName(const string &newName)
{
    name = newName;
}

/**
    The setIdNumber sets the employee's id.
    @param newId The employee's id.
 */
void EmployeeInfo::setIdNumber(int newId)
{
    idNumber = newId;
}

/**
    The overloaded operator < accepts another EmployeeInfo object
    and returns true if the id number in the calling object is less
    than the id number if the argument object. Otherwise, it returns false.
    @param other The other EmployeeInfo object.
    @return True if this id number is less than other id number.
            False otherwise.
 */
bool EmployeeInfo::operator < (const EmployeeInfo &other) const
{
    return (this->idNumber < other.idNumber);
}

/**
    The overloaded operator > accepts another EmployeeInfo object
    and returns true if the id number in the calling object is greater
    than the id number if the argument object. Otherwise, it returns false.
    @param other The other EmployeeInfo object.
    @return True if this id number is greater than other id number.
            False otherwise.
 */
bool EmployeeInfo::operator > (const EmployeeInfo &other) const
{
    return (this->idNumber > other.idNumber);
}

/**
    The overloaded operator == accepts another EmployeeInfo object
    and returns true if the id numbers in the calling object and the
    argument object are the same. Otherwise, it returns false.
    @param other The other EmployeeInfo object.
    @return True if id numbers are the same in both objects.
            False otherwise.
 */
bool EmployeeInfo::operator == (const EmployeeInfo &other) const
{
    return (this->idNumber == other.idNumber);
}

/**
    The overloaded assignment = operator copies the data of the other
    object to this object.
    @param other The other object.
    @return This object with newly copied data.
 */
EmployeeInfo &EmployeeInfo::operator = (const EmployeeInfo &other)
{
    // Copy the employee's name.
    this->name = other.name;

    // Copy the employee's id number.
    this->idNumber = other.idNumber;

    // Return this newly copied object.
    return *this;
}

/**
    The overloaded cout <<  operator displays the information of an
    employee on the screen.
    @param strm The cout stream object.
    @param obj An EmployeeInfo object.
    @return A cout stream object.
 */
ostream &operator << (ostream &strm, const EmployeeInfo &obj)
{
    strm << "Name: " << obj.getName() << endl;
    strm << "ID: " << obj.getIdNumber() << endl;
    return strm;
}