#include <iostream>
#include <string>
using namespace std;

// Structure declaration.
struct MovieData {
    string title;           // The title of the movie.
    string director;        // The director of the movie.
    int releasedYear;       // The year that the movie is released.
    double runningTime;     // The running time of the movive (in minutes).
};

// Function prototypes.
void displayMovieData(const MovieData * const);       // Function to display the data of the movie.

// The main function.
int main()
{
    // Define an array of two MovieData objects.
    MovieData *arrPtr = new MovieData[2];

    // Initialize the two elements with sample data.
    arrPtr[0] = { "Inception", "Christopher Nolan", 2010, 148 };
    arrPtr[1] = { "Spirited Away", "Hayao Miyazaki", 2001, 125};

    // Display the movide data.
    for (int count = 0; count < 2; count++)
    {
        cout << "Movie #" << (count + 1) << ":\n";
        displayMovieData(&arrPtr[count]);
        cout << endl;
    }

    // Delete dynamically allocated memory.
    delete [] arrPtr;

    return 0;
}
/**
 * Function displayMovieData: The function accepts a MovieData instance and then displays
 * the information of the object to the screen.
 */
void displayMovieData(const MovieData *movie)
{
    cout << "Title: " << movie->title << endl;
    cout << "Director: " << movie->director << endl;
    cout << "Released Year: " << movie->releasedYear << endl;
    cout << "Running Time: " << movie->runningTime << " minutes." << endl;
}