#include <iostream>
#include <string>
#include <cctype>
#include "StaticQueue.h"
using namespace std;

// Constants for the data type.
const char INT_TYPE = 'I',
           DOUBLE_TYPE = 'D',
           STRING_TYPE = 'S';

// Constants for the menu choice.
const int ENQUEUE_CHOICE = 1,
          DEQUEUE_CHOICE = 2,
          QUIT_CHOICE = 3;

// Function prototypes.
void getDataType(char &);
void menu(int &);
void getQueueSize(int &);

template <class T>
void equeueItem(StaticQueue<T> &);

template <class T>
void dequeueItem(StaticQueue<T> &);

int main()
{
    char type;

    getDataType(type);

    cout << type << endl;

    return 0;
}
/**
 * Function getDataType(char &): gets the user's desired data type and
 * saves into the reference parameter.
 * @param type: The reference parameter to hold the user's data type.
 * @return void.
 */
void getDataType(char &type)
{
    // Display the menu of data type.
    cout << "Which data type do you want to work with?\n"
         << INT_TYPE
         << " - Integers\n"
         << DOUBLE_TYPE
         << " - Double\n"
         << STRING_TYPE
         << " - String\n"
         << "Enter your choice: ";
    cin >> type;
    cin.ignore();

    // Validate the user's choice.
    while (toupper(type) != INT_TYPE && toupper(type) != DOUBLE_TYPE && toupper(type) && STRING_TYPE)
    {
        cout << "Enter a valid data type: ";
        cin >> type;
    }
}

/**
 * Function menu(int &): displays the menu and gets the user's menu choice,
 * and saves it into the reference parameter.
 * @param choice: The reference parameter to hold the user's choice.
 * @return void.
 */
void menu(int &choice)
{
    // Displays the menu and gets the user's choice.
    cout << "\nWhat do you want to do?\n"
         << ENQUEUE_CHOICE
         << " - Enqueue an item into the queue\n"
         << DEQUEUE_CHOICE
         << " - Dequeue an item from the queue\n"
         << QUIT_CHOICE
         << " - Quit the queue\n"
         << "Enter your choice: ";
    cin >> choice;

    // Validate the user's choice.
    while (choice < ENQUEUE_CHOICE || choice > DEQUEUE_CHOICE)
    {
        cout << "Enter a valid choice: ";
        cin >> choice;
    }
}

/**
 * Function - getQueueSize(int &): gets the queue size and saves it into
 * the reference parameter.
 * @param size: The reference parameter to holds the size of the queue.
 * @return void.
 */
void getQueueSize(int &size0)