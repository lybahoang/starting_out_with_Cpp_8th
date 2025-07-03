// This program demonstrates the StaticQueue class with the Student
// data type.
#include <iostream>
#include <string>
#include <cctype>
#include "Student.h"
#include "StaticQueue.h"
using namespace std;

int main()
{
    // Create an array of 3 Student objects.
    Student *studentList = new Student[3];
    studentList[0] = Student("John", 19, "CS", "1234");
    studentList[1] = Student("Jack", 20, "Accounting", "1235");
    studentList[2] = Student("Anna", 21, "Engineering", "1236");

    // Create a queue of Student type.
    StaticQueue<Student> myStudentQueue(3);

    // Enqueue the three students into the queue.
    myStudentQueue.enqueue(studentList[0]);
    myStudentQueue.enqueue(studentList[1]);
    myStudentQueue.enqueue(studentList[2]);

    // Dequeue a student and display the student's information.
    Student catchVar;
    int count = 0;      // Loop counter.
    while (!myStudentQueue.isEmpty())
    {
        myStudentQueue.dequeue(catchVar);
        cout << "Student #" << (++count) << endl;
        catchVar.displayInfo();
        cout << endl << endl;
    }

    return 0;
}
