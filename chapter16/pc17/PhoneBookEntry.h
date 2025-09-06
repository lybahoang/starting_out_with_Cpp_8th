#ifndef PHONE_BOOK_ENTRY_H
#define PHONE_BOOK_ENTRY_H
#include <string>
#include <iostream>
using namespace std;

class PhoneBookEntry
{
protected:
    string name;
    string phoneNumber;

public:
    // Default constructor.
    PhoneBookEntry()
        { name = "";
          phoneNumber = ""; }
        
    // Constructor.
    PhoneBookEntry(const string &n, const string &pNumber)
        { name = n;
          phoneNumber = pNumber; }
    
    // Accessor functions.
    const string &getName() const
        { return name; }
    
    const string &getPhoneNumber() const
        { return phoneNumber; }
    
    // Mutator functions.
    void setName(const string &newName)
        { name = newName; }
    
    void setPhoneNumber(const string &newNumber)
        { phoneNumber = newNumber; }
    
    // Other functions.
    void displayInfo() const
        {
            cout << "Name: " << name << endl;
            cout << "Phone number: " << phoneNumber << endl;
        }
};
#endif