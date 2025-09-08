#include "Student.h"
#include <iostream>

/**
 * Default constructor: Assigns default values to member variables.
 */
Student::Student()
{
    name = "";
    age = 0;
    major = "";
    studentID = "";
}

/**
 * Constructor: Accepts four arguments and assigns them into member variables.
 */
Student::Student(const string &stuName, int stuAge, const string &stuMajor, const string &id)
{
    name = stuName;
    age = stuAge;
    major = stuMajor;
    studentID = id;
}

/**
 * Function setName: Accepts an argument and assigns it to the 'name' member variable.
 */
void Student::setName(const string &newName)
{
    name = newName;
}

/**
 * Function setAge: Accepts an argument and assigns it to the 'age' member variable.
 */
void Student::setAge(int newAge)
{
    age = newAge;
}

/**
 * Function setMajor: Accepts an argument and assigns it to the 'major' member variable.
 */
void Student::setMajor(const string &newMajor)
{
    major = newMajor;
}

/**
 * Function setID: Accepts an argument and assigns it to the 'studentID' member variable.
 */
void Student::setID(const string &newID)
{
    studentID = newID;
}

/**
 * Function getName: Returns the name of the student.
 */
const string &Student::getName() const
{
    return name;
}

/**
 * Function getAge: Returns the age of the student.
 */
int Student::getAge() const
{
    return age;
}

/**
 * Function getMajor: Returns the major of the student.
 */
const string &Student::getMajor() const
{
    return major;
}

/**
 * Function getID: Returns the identification number of the student.
 */
const string &Student::getID() const
{
    return studentID;
}

/**
 * Function displayInfo: Displays all information of the student.
 */
void Student::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Major: " << major << endl;
    cout << "ID: " << studentID;
}