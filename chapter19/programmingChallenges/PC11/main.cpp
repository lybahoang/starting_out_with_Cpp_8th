#include <cctype>
#include <iostream>
#include <string>
using namespace std;

/**
 * The getLetters function accepts a string and returns the new string, which
 * consists of letters only.
 * @param inputString The string.
 * @return The new string without whitespace characters.
 */
string getLetters(const string &inputString)
{
    string outputString = "";    // To hold output string.

    // Scan the input string and take letters only.
    for (int index = 0; index < inputString.length(); index++)
    {
        if (isalpha(inputString[index]))
        {
            outputString += inputString[index];
        }
    }

    return outputString;
}

/**
 * The toLowercase function accepts a string and convert all of its letters
 * to the lowercase style and return that new string
 * @param inputString The input string
 * @return The string in lowercase style
 */
string toLowercase(const string &inputString)
{
    string outputString = "";   // To hold output string.

    // Scan the input string and convert its letters to lowercase.
    for (int index = 0; index < inputString.length(); index++)
    {
        outputString += tolower(inputString[index]);
    }

    return outputString;
}

/**
 * The checkPalindrome function accepts a string and returns true if the string
 * reads the same forward and backward. Otherwise, it returns false
 * @param inputString The input string
 * @param True or False
 */
bool checkPalindrome(const string &inputString)
{
    int strLength = inputString.length();
    // Base case: If the string is empty or contains only one characters
    // then returns true.
    if (strLength == 0 || strLength == 1)
    {
        return true;
    }

    return ((inputString[0] == inputString[strLength - 1]) &&
           checkPalindrome(inputString.substr(1, strLength - 2)));
}

/**
 * The checkPalindrome2 shows another recursive way to check for a palindrome
 */
bool checkPalindrome(const string &inputString, int start, int end)
{
    // Base case: If the input string is empty or contains only one character, then
    // returns true.
    if (start >= end)
    {
        return true;
    }
    // Recursive step.
    return (inputString[start] == inputString[end] && 
            checkPalindrome(inputString, start + 1, end - 1));
}

/**
 * The isPalindrome function calls the checkPalindrome function
 */
bool isPalindrome(const string &inputString)
{
    // Process the input string.
    string processedStr = toLowercase(getLetters(inputString));

    // Return the result.
    return checkPalindrome(processedStr, 0, processedStr.length() - 1);
}

int main()
{
    // Create an array of string to test the function.
    string inputStringArray[5] = {
            "A man, a plan, a canal, Panama",
            "Able was I, ere I saw Elba",
            "Desserts, I stressed",
            "Kayak",
            "Bottle of water" };

    // Check which elements in the array is a palindrome.
    for (int index = 0; index < 5; index++)
    {
        cout << "\"" << inputStringArray[index] << "\" ";
        cout << (isPalindrome(inputStringArray[index]) ? "is a palindrome.\n" :
                 "is not a palindrome.\n");
    }
    
    return 0;
}