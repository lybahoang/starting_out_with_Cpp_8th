#include "DynamicQueue.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    // Create two DynamicQueue object with char data type.
    DynamicQueue<char> myCharQueue1;
    DynamicQueue<char> myCharQueue2;

    // Create two file stream objects to read data from.
    ifstream inputFile1("textFile1.txt");
    ifstream inputFile2("textFile2.txt");

    // Check if the two files are opened successfully.
    if (inputFile1.fail() || inputFile2.fail())
    {
        cout << "Error: Could not open the files.\n";
        exit(EXIT_FAILURE);
    }

    // Read characters in inputFile1 to myCharQueue1.
    char character;     // To hold a character.

    while (inputFile1.get(character))
    {
        myCharQueue1.enqueue(character);
    }

    // Read characters in inputFile2 to myCharQueue2.
    while (inputFile2.get(character))
    {
        myCharQueue2.enqueue(character);
    }

    // Close two input files.
    inputFile1.close();
    inputFile2.close();

    // Check if the contents of the two files are identical.
    // If the length of the two files are not equal to each other, then its contents are
    // not the same.
    bool isIdentical = true;       // A flag to indicate the files are identical.

    if (myCharQueue1.getNumNodes() != myCharQueue2.getNumNodes())
    {
        isIdentical = false;
    }
    // Otherwise, compare each character in the two files.
    else
    {
        // Variables to hold characters in the files.
        char character1, character2;

        // Scan the queues.
        while (!myCharQueue1.isEmpty())
        {
            // Take characters in each queue one-by-one.
            myCharQueue1.dequeue(character1);
            myCharQueue2.dequeue(character2);

            // If the two characters are not the same, update flags.
            if (character1 != character2)
            {
                isIdentical = false;
                break;
            }
        }
    }

    // Display the checking result.
    if (isIdentical)
    {
        cout << "The two files are identical." << endl;
    }
    else
    {
        cout << "The two files are not identical." << endl;
    }

    return 0;
}