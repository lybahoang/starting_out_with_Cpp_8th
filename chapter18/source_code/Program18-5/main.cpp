#include <iostream>
#include <string>
#include "../DynamicStack.h"
using namespace std;

// Constants for the menu choice.
const int PUSH_CHOICE = 1,
          POP_CHOICE = 2,
          QUIT_CHOICE = 3;

// Function prototypes.
void menu(int &);
void getStackSize(int &);
void pushItem(DynamicStack<string> &);
void popItem(DynamicStack<string> &);

int main()
{
    int choice;     // To hold a menu choice.

    // Create the stack of string.
    DynamicStack<string> stack;

    do
    {
        // Get the user's menu choice.
        menu(choice);

        // Perform the user's choice.
        if (choice != QUIT_CHOICE)
        {
            switch (choice)
            {
                case PUSH_CHOICE:
                    pushItem(stack);
                    break;
                case POP_CHOICE:
                    popItem(stack);
                    break;
            }
        }
    } while (choice != QUIT_CHOICE);

    return 0;
}

/***
 * Function menu(int &).
 * The function displays the menu and gets the user's choice, 
 * which is assigned to the reference parameter.
 */
void menu(int &choice)
{
    // Display the menu and get the user's choice.
    cout << "\nWhat do you want to do?\n"
         << PUSH_CHOICE
         << " - Push an item onto the stack.\n"
         << POP_CHOICE
         << " - Pop an item off the stack.\n"
         << QUIT_CHOICE
         << " - Quit the program.\n"
         << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    // Validate the choice
    while (choice < PUSH_CHOICE || choice > QUIT_CHOICE)
    {
        cout << "Enter a valid choice: ";
        cin >> choice;
        cin.ignore();
    }
}

/***
 * Function getStackSize(int &).
 * The function gets the desired stack size, which is assigned
 * to the reference parameter.
 */
void getStackSize(int &size)
{
    // Get the desired stack size.
    cout << "How big should I make the stack? ";
    cin >> size;
    cin.ignore();

    // Validate the size.
    while (size < 1)
    {
        cout << "Enter 1 or greater: ";
        cin >> size;
    }
}

/***
 * Function pushItem(DynamicStack<string> &).
 * The function gets an item from the user and pushes the item
 * onto the stack.
 */
void pushItem(DynamicStack<string> &stack)
{
    string item;

    // Get an item to push onto the stack.
    cout << "\nEnter an item: ";
    getline(cin, item);
    stack.push(item);
}

/***
 * Function popItem(DynamicStack<string> &).
 * The function pops an item off the stack and displays it.
 */
void popItem(DynamicStack<string> &stack)
{
    string item = "";

    // Pop the item off the stack.
    stack.pop(item);

    // Display the item.
    if (item != "")
        cout << item << " was popped.\n";
}