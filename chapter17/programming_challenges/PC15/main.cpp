#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an IntegerList object.
    IntegerList myList;

    // Initialize the list with some values.
    for (int count = 0; count < 5; count++)
    {
        myList.appendNode(count * 5);
    }

    // Display the values in the list.
    cout << "Here are values in the list.\n";
    myList.displayList();

    // Pop back the list.
    cout << "\nPopping back the list.";
    myList.pop_back();

    // Display the values in the list.
    cout << "\nHere are values in the list.\n";
    myList.displayList();
    cout << endl;

    // Pop front the list.
    cout << "\nPopping front the list.";
    myList.pop_front();

    // Display the values in the list.
    cout << "\nHere are values in the list.\n";
    myList.displayList();
    cout << endl;
    
    // Push back 90 to the list.
    cout << "\nPushing back 90 to the list.";
    myList.push_back(90);
    
    // Display the values in the list.
    cout << "\nHere are values in the list.\n";
    myList.displayList();
    cout << endl;
    
    // Push front -90 to the list.
    cout << "\nPushing back -90 to the list.";
    myList.push_front(-90);
    
    // Display the values in the list.
    cout << "\nHere are values in the list.\n";
    myList.displayList();
    cout << endl;

    return 0;
}