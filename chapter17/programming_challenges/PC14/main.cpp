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
        myList.appendNode(count * 2 + 1);
    }

    // Display the list.
    cout << "Here are values in myList.\n";
    myList.displayList();

    // Display the list using opeartor[].
    cout << "\nHere are values in myList.\n";
    for (int count = 0; count < myList.countNode(); count++)
    {
        try
        {
            cout << myList[count] << " ";
        }
        catch (IntegerList::InvalidIndex i)
        {
            cout << "Error: " << i.getInvalidIndex();
            cout << " is an invalid index.\n";
        }
    }

    return 0;
}