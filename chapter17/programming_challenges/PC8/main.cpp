#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an integer list and a double list.
    List<int> integerList;
    List<double> doubleList;

    // Initializes the lists with some values.
    for (int count = 0; count < 5; count++)
    {
        integerList.appendNode(count + 25);
        doubleList.appendNode(count * 2.7);
    }

    // Display the integer list.
    cout << "Here are values in integerList.\n";
    integerList.displayList();

    // Display values in the doubleList.
    cout << "\nHere are values in doubleList.\n";
    doubleList.displayList();

    return 0;
}