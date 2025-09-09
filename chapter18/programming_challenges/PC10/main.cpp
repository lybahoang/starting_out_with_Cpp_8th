#include "DynamicQueue.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
    // Create a DynamicQueue object of the char data type.
    DynamicQueue<char> *myCharDynamicQueue = new DynamicQueue<char>;

    // Create a file stream object to open an input file.
    ifstream inputFile;

    // Open input file.
    inputFile.open("originalFile.txt");

    // Check if the file was successfully opened.
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file originalFile.txt\n";
        exit(EXIT_FAILURE);
    }

    char character;     // To hold a character in the file.

    // Read the content of the file character-by-character and enqueue it.
    while (inputFile.get(character))
    {
        myCharDynamicQueue->enqueue(character);
    }

    // Close the input file.
    inputFile.close();

    // Create a file stream to write data to it.
    ofstream outputFile;

    // Open the file.
    outputFile.open("uppercaseFile.txt");

    // Dequeue the characters in the queue and convert it to uppercase and then
    // write it to outputFile.
    while (!(myCharDynamicQueue->isEmpty()))
    {
        // Dequeue the front character.
        myCharDynamicQueue->dequeue(character);

        // Write the uppercase version of the character to outputFile.
        outputFile.put(toupper(character));
    }

    // Close the output file.
    outputFile.close();
    
    // Delete the dynamic allocated memory.
    delete myCharDynamicQueue;
}