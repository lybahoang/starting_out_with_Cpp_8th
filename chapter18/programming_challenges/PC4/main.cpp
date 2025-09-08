// This program demonstrates the DynamicQueue template class for the
// Phone data type.
#include <iostream>
#include "DynamicQueue.h"
#include "Phone.h"
using namespace std;

int main()
{
    const int NUM_PHONES = 4;   // Array size.

    // Create an array of four Phone objects in the heap.
    Phone *phoneList = new Phone[NUM_PHONES];

    // Intialize the array with four demo phone information.
    phoneList[0] = Phone("Iphone", "Gold", "Iphone XS");
    phoneList[1] = Phone("Iphone", "Black", "Iphone 15 Promax");
    phoneList[2] = Phone("Samsung", "Black", "Galaxy J7 Pro");
    phoneList[3] = Phone("Samsung", "Gray", "Galaxy J5");

    // Create a DynamicQueue object.
    DynamicQueue<Phone> phoneQueue;

    // Enqueue the four objects into the 
    for (int count = 0; count < NUM_PHONES; count++)
        phoneQueue.enqueue(phoneList[count]);

    // Dequeue the queue and display the information.
    Phone catchVar;

    while (!phoneQueue.isEmpty())
    {
        phoneQueue.dequeue(catchVar);
        catchVar.displayInfo();
        cout << endl << endl;
    }

    return 0;
}