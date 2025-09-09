#include "DynamicStack.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    // Create a DynamicStack object of the char data type.
    DynamicStack<char> *myCharStackPtr = new DynamicStack<char>();

    // Create a file stream object to open the input file.
    ifstream inputFile;
    
    // Open the file.
    inputFile.open("originalFile.txt");

    // Determine if the file was successfully opened.
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file originalFile.txt.\n";
        exit(EXIT_FAILURE);
    }

    char character;     // To hold a character in the file.
    
    // Read characters in inputFile into the stack.
    while (inputFile.get(character))
    {
        // Push the character onto the stack.
        myCharStackPtr->push(character);
    }

    // Close inputFile.
    inputFile.close();

    // Create a file stream object to write the characters in the stack
    // to the file in reversed order.
    ofstream outputFile;

    // Open the file.
    outputFile.open("reversedFile.txt");

    // Write characters in the stack to outputFile.
    while (!myCharStackPtr->isEmpty())
    {
        // Pop the character off the stack.
        myCharStackPtr->pop(character);

        // Write the character to outputFile.
        outputFile.put(character);
    }

    // Close outputFile.
    outputFile.close();

    // Display a message after the process.
    cout << "The stack is " << (myCharStackPtr->isEmpty() ? "empty.\n" : "not empty.\n"); 
    cout << "Reverse file successfully.\n";

    // Delete dynamically allocated memory.
    delete myCharStackPtr;
    return 0;
}