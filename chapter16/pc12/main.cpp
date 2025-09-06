#include "SimpleVector.h"
#include "SearchableVector.h"
#include "SortableVector.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an object from SimpleVector class
    // that works with string data type.
    SimpleVector<string> sportList(4);
    // Create an object from SearchVector class
    // that works with string data type.
    SortableVector<string> sortableList(4);

    // Initialize the object with some string literals.
    sportList[0] = "Soccer";
    sportList[1] = "Badminton";
    sportList[2] = "Basketball";
    sportList[3] = "Pickle ball";

    // Display the values in sportList.
    cout << "Here are sports in sportList.\n";
    for (int count = 0; count < 4; count++)
        cout << sportList[count] << endl;
    
    // Initalize sortableList with some strings.
    for (int count = 0; count < 4; count++)
        sortableList[count] = sportList[count];

    // Display the values in sortableList.
    cout << "\nHere are sports in sortableList.\n";
    for (int count = 0; count < 4; count++)
        cout << sortableList[count] << endl;

    // Sort the sortableList.
    cout << "\nSort the sortableList.\n";
    sortableList.sortAscending();

    // Display the values in sortableList.
    cout << "\nHere are sports in sortableList.\n";
    sortableList.displayArray();

    // Create an object from the SearchableVector class.
    SearchableVector<string> searchableList(4);

    // Initalize it with some strings.
    for (int count = 0; count < 4; count++)
        searchableList[count] = sportList[count];

    // Display the values in searchableList.
    cout << "\nHere are sports in searchableList.\n";
    searchableList.displayArray();

    // Sort and search for "Soccer" in searchableList.
    cout << "\nSort and search for \"Soccer\" in searchableList.\n";
    if (searchableList.sortAndSearch("Soccer") == -1)
        cout << "Soccer is not in the list.\n";
    else
        cout << "Soccer was found.\n";

    // Push a new sport to the back of sportList.
    cout << "\nPusing \"Tennis\" back.\n";
    sportList.push_back("Tennis");
    
    while (sportList.getSize() > 0)
    {
        // Display the values in the object.
        cout << "There are " << sportList.getSize() << " sports.\n";
        cout << "Here are sports in sportList.\n";
        sportList.displayArray();
        
        // Pop back the last element.
        cout << "\nPopping back the last element, ";
        cout << "which is ";
        cout << sportList.getElementAt(sportList.getSize() - 1);
        sportList.pop_back();
        cout << endl;
    }

    // Display the values in the object.
    sportList.displayArray();
    
    return 0;
}