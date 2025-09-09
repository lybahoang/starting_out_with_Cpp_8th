/**
 * This program is an alternative to PC9 by using the Standard Template Library.
 */

#include <fstream>
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

int main()
{
    // Define an STL stack of char data type.
    stack< char > *myCharStack = new stack< char >;

    // Create two file stream objects: one for input file and one for output file.
    ifstream inputFile("originalFile.txt");     // Input file.
    ofstream outputFile("reversedFile.txt");    // Output file.

    // Check if the input file was successfully opened.
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file originalFile.txt\n";
        exit(EXIT_FAILURE);
    }

    // Read each character in inputFile to the stack.
    char character;     // To hold a character in the file.

    while (inputFile.get(character))
    {
        myCharStack->push(character);
    }

    // Close inputFile.
    inputFile.close();

    // Write the data in the stack to the file so that the contents of the 
    // file is reversed.
    while (!myCharStack->empty())
    {
        // Take the top character in the stack.
        character = myCharStack->top();

        // Write the character to outputFile.
        outputFile.put(character);

        // Remove the top character in the stack.
        myCharStack->pop();
    }

    // Close outputFile.
    outputFile.close();

    // Delete dynamically allocated memory.
    delete myCharStack;

    return 0;
}