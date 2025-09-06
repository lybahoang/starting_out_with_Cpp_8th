#include "PhoneBookEntry.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Create a vector of PhoneBookEntry objects.
    vector<PhoneBookEntry> myPhoneBook {
        PhoneBookEntry("Hoang", "2500509"),
        PhoneBookEntry("Hiep", "20083009"),
        PhoneBookEntry("Dung", "1271977"),
        PhoneBookEntry("Vitamin", "060324"),
        PhoneBookEntry("Carnegie", "7396825")
    };

    // Display the contents of each object using an iterator.
    vector<PhoneBookEntry>::iterator iter;  // Define an interator.
    int index = 1;  // Loop counter.

    cout << "Here are contents in each object.\n";
    for (iter = myPhoneBook.begin(); iter < myPhoneBook.end(); iter++)
    {
        cout << "Object #" << index++ << ".\n";
        iter->displayInfo();
        cout << endl;
    }

    return 0;
}