/**
 * This is an alternative solution to PC 10 chapter 18, which is going
 * to use the queue header file.
 */

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Create a Queue object of char data type.
    queue< char > *myCharQueue = new queue< char >;

    // Create a file stream object and open the file for reading.
    ifstream inputFile("originalFile.txt");

    // Check if inputFile was successfully opened.
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file originalFile.txt\n";
        exit(EXIT_FAILURE);
    }

    // While the file is not at the end, read a character and push it
    // into the queue.
    char character;     // To hold a character.

    while (inputFile.get(character))
    {
        myCharQueue->push(character);
    }
    
    // Close inputFile after reading.
    inputFile.close();

    // Create an output file stream to write data to.
    ofstream outputFile("uppercaseFile.txt");

    // Write letters in uppercase to the file.
    while (!(myCharQueue->empty()))
    {
        // Take the character at the front of the queue.
        character = myCharQueue->front();

        // Write its uppercase style to outputFile.
        outputFile.put(toupper(character));

        // Remove the front character from the queue.
        myCharQueue->pop();
    }

    // Close outputFile after writing.
    outputFile.close();

    // Delete dynamically allocated memory.
    delete myCharQueue;

    return 0;
}