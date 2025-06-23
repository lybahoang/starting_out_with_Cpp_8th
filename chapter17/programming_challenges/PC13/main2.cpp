// This program reads the data from a file into a linked list
// and displays it on the screen.
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a LinkedList object.
    LinkedList <double> myData;

    // Read the data from a file to the linked list.
    myData.readFromFile("rainfall.txt");

    // Display the values in the linked list.
    cout << "Here are values in the linked list.\n";
    myData.display();

    return 0;
}
