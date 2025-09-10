#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Create two queue object of char data type.
    queue<char> charQueue1;
    queue<char> charQueue2;

    // Create two file stream objects to read data from.
    ifstream inputFile1("textFile1.txt");
    ifstream inputFile2("textFile2.txt");

    // Check if the two files were opened successully.
    if (inputFile1.fail() || inputFile2.fail())
    {
        cout << "Error: Could not open the files." << endl;
        exit(EXIT_FAILURE);
    }
    
    // Read each character in inputFile1 and enqueue it into charQueue1.
    char character1;        // To hold a character.

    while (inputFile1.get(character1))
    {
        charQueue1.push(character1);
    }

    // Read each character in inputFile2 and enqueue it into charQueue2.
    char character2;        // To hold a character.

    while (inputFile2.get(character2))
    {
        charQueue2.push(character2);
    }

    // Close the two files.
    inputFile1.close();
    inputFile2.close();

    // Check if the contents of the two files are identical.
    bool isIdentical = true;    // A flag indicating the two files are identical.

    // If the lengths of the two files are not equal to each other, then
    // their contents are not the same.
    if (charQueue1.size() != charQueue2.size())
    {
        isIdentical = false;
    }
    // Otherwise, check each character of the two files.
    else
    {
        while (!charQueue1.empty())
        {
            // Take each character in the two files.
            character1 = charQueue1.front();
            character2 = charQueue2.front();

            // Remove the front values in the two queues.
            charQueue1.pop();
            charQueue2.pop();

            // If the two characters are not the same, set isIdentical
            // to false.
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