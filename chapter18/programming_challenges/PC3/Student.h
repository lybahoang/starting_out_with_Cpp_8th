// Specification file for the Student class.
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;
    string major;
    string studentID;

public:
    // Default constructor.
    Student();

    // Constructor.
    Student(const string &, int, const string &, const string &);

    // Mutator functions.
    void setName(const string &);
    void setAge(int);
    void setMajor(const string &);
    void setID(const string &);

    // Accessor functions.
    const string &getName() const;
    int getAge() const;
    const string &getMajor() const;
    const string &getID() const;

    // Other functions.
    void displayInfo() const;
};
#endif