// This driver program demonstrates the DynamicStack template class
// with the double data type.
#include <iostream>
#include "DynamicStack.h"
using namespace std;

// Constants for the menu choice.
const int PUSH_CHOICE = 1,
          POP_CHOICE = 2,
          QUIT_CHOICE = 3;

// Function prototypes.
void menu(int &);
void pushItem(DynamicStack<double> &);
void popItem(DynamicStack<double> &);

int main()
{
    int choice;     // To hold the menu choice.

    // Create a DynamicStack for double.
    DynamicStack<double> dStack;

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
                    pushItem(dStack);
                    break;
                case POP_CHOICE:
                    popItem(dStack);
                    break;
            }
        }
    } while (choice != QUIT_CHOICE);

    return 0;
}
/**
 * Function menu(int &).
 * This function displays the menu and gets the user's choice and assigns
 * the user's choice into the reference parameter.
 * @param choice: The reference parameter to hold the user's choice.
 * @return void.
 */
void menu(int &choice)
{
    // Displays the menu and gets the user's choice.
    cout << "What do you want to do?\n"
         << PUSH_CHOICE
         << " - Push an item onto the stack\n"
         << POP_CHOICE
         << " - Pop an item off the stack\n"
         << QUIT_CHOICE
         << " - Quit the program\n"
         << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    // Validate the user's choice.
    while (choice < PUSH_CHOICE || choice > QUIT_CHOICE)
    {
        cout << "Please eneter a valid choice: ";
        cin >> choice;
    }
}

/**
 * Function pushItem(DynamicStack<double> &).
 * The function takes a DynamicStack object, gets and push an item pushed onto 
 * the stack from the user.
 * @param stack: The stack that the item is pushed onto.
 * @return void.
 */
void pushItem(DynamicStack<double> &stack)
{
    // Gets the item pushed onto the stack.
    double item;

    cout << "What do you want to push onto the stack? ";
    cin >> item;

    // Pushes the item onto the stack.
    stack.push(item);
}

/**
 * Function popItem(DynamicStack<double> &).
 * The function takes a DynamicStack object, pops the top value of the stack, and
 * displays the value.
 * @param stack: The stack that the item is pushed onto.
 * @return void.
 */
void popItem(DynamicStack<double> &stack)
{
    double catchVar;    // To hold the value popped off the stack.

    // Pop the value off the stack.
    stack.pop(catchVar);

    // Display the value.
    if (!stack.isEmpty())
        cout << catchVar << " was popped.\n";
}