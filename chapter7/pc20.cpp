// This program simulate a theater seating to sell tickets to performance.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

// Global constants for the number of rows and seats.
const int NUM_ROWS = 15;
const int NUM_SEATS = 30;

// Constants for user's choice.
const int OPTION_1 = 1;
const int OPTION_2 = 2;
const int OPTION_3 = 3;
const int OPTION_4 = 4;

// Function prototypes.
void displayMenu();
void getOption(int &);
void getSeatSold(int &, int &);
void getRowPrices(double [], int, string);
double calculateTotalSales(const double [], int);
bool checkSeatSold(int, int);
bool checkSeatAvailable(const bool [][NUM_SEATS], int, int, int);
void updateSeatingChart(bool [][NUM_SEATS], int, int, int);
void displaySeatingChart(const bool [][NUM_SEATS], int);
void displayReport(const bool [][NUM_SEATS], int);

int main()
{
    // Variable to keep user's choice.
    int choice;

    // Variables to keep the position of seat.
    int row, seat;

    // Declare an 2D array two illustrate the seating chart.
    bool seatingChart[NUM_ROWS][NUM_SEATS];
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int seat = 0; seat < NUM_SEATS; seat++)
        {
            seatingChart[row][seat] = true;
        }
    }

    // Declare an array to keep the prices for each row.
    double rowPrices[NUM_ROWS];
    
    // Read the prices of each row from a file.
    getRowPrices(rowPrices, NUM_ROWS, "rowPrices.txt");

    // Declare an array to keep the total sales for each row.
    double rowSales[NUM_ROWS];
    for (double &row : rowSales)
    {
        row = 0;
    }

    // Initialize the seating chart so that it says that all seats are available.
    do
    {
        // Display the seating chart.
        displaySeatingChart(seatingChart, NUM_ROWS);

        // Get user's option.
        getOption(choice);

        // If user chooses to enter the seat being sold.
        if (choice == OPTION_1)
        {
            // Variable to keep entering the seat.
            char again;

            // Variable to store the total of the purchase.
            double totalPurchaseAmount = 0.0;

            do
            {
                // Get the position of the seat being sold.
                getSeatSold(row, seat); 
    
                // If the position of the seat is valid and avalable.
                if (checkSeatSold(row, seat) && checkSeatAvailable(seatingChart, NUM_ROWS, row, seat))
                {
                    // Update the total purchases.
                    totalPurchaseAmount += rowPrices[row - 1];
    
                    // Update the total sales of the corresponding row.
                    rowSales[row - 1] += rowPrices[row - 1];
    
                    // Update the seating chart.
                    updateSeatingChart(seatingChart, NUM_ROWS, row, seat);
                }
                // If the position of the seat is invalid.
                else if (!checkSeatSold(row, seat))
                {
                    cout << "Sorry. The position is invalid.\n";
                }
                // If the position of the seat is not available.
                else if (!checkSeatAvailable(seatingChart, NUM_ROWS, row, seat))
                {
                    cout << "Sorry. The seat had been sold.\n";
                }
                
                cout << "Do you want to enter another seat (Y/N)? ";
                again = cin.get();
                
            } while (again == 'y' || again == 'Y');

            // Display the total ticket prices.
            cout << "The total purchase amount: $" << totalPurchaseAmount << endl;
        }

        // If user chooses to display the total sales.
        if (choice == OPTION_2)
        {
            cout << "The total amount of sales is $" << calculateTotalSales(rowSales, NUM_ROWS) << endl;
        }

        // If user chooses to display a report.
        if (choice == OPTION_3)
        {
            displayReport(seatingChart, NUM_ROWS);
        }

        // If user chooses to exit the program.
        if (choice == OPTION_4)
        {
            cout << "Exit the program successfully.\n";
        }
    } while (choice != OPTION_4);



    return 0;
}

/***
 * Function displayMenu(): The function display the menu.
 */
void displayMenu()
{
    cout << "--- MENU ---\n"
         << "Option 1. Enter the seat being sold.\n"
         << "Option 2. Display the total sales.\n"
         << "Option 3. Display the report.\n"
         << "Option 4. Exit the program.\n"
         << "Enter your choice (1 - 4): ";
}

/***
 * Function getOption(): The function displays menu, prompts for user's choice,
 * validate it, and then returns it.
 */
void getOption(int &choice)
{
    do
    {
        // Display the menu.
        displayMenu();

        // Get user's choice.
        cin >> choice;
        cin.ignore();

        // Validate the user's choice.
        if (choice > OPTION_4 || choice < OPTION_1)
        {
            cout << "Invalid choice. Please enter again.\n\n";    
        }
    } while (choice > OPTION_4 || choice < OPTION_1);
}

/***
 * Function displaySeatingChart: The function display the seating chart to the screen.
 * @para: A 2D array storing the seats.
 */
void displaySeatingChart(const bool seats[][NUM_SEATS], int numRows)
{
    const char AVAILABLE_SEAT = '#';
    const char TAKEN_SEAT = '*';

    // Display the title of the seating chart.
    cout << "\n\t\t\t\t\tSeating Chart\n";
    cout << left << setw(10) << "";
    for (int count = 1; count <= NUM_SEATS; count++)
    {
        cout << setw(3) << count;
    }
    cout << endl;

    // Display the seats in each row in the seating chart.
    for (int row = 0; row < numRows; row++)
    {
        cout << left << "Row " << setw(6) << (row + 1);
        for (int seat = 0; seat < NUM_SEATS; seat++)
        {
            // If the seat is available, display '#'.
            if (seats[row][seat] == true)
            {
                cout << setw(3) << AVAILABLE_SEAT;
            }
            // Otherwise, display '*' to represent a taken seat.
            else
            {
                cout << setw(3) << TAKEN_SEAT;
            }
        }
        cout << endl;
    }
}

/***
 * Function updateSeatingChart: The function marks the seats that are sold
 * in the seating chart.
 * @para: An 2D array about the seating chart.
 * @para: The number of rows.
 * @para: The row and number of the seat being sold.
 */
void updateSeatingChart(bool seats[][NUM_SEATS], int numRows, int row, int seat)
{
    seats[row - 1][seat - 1] = false;
}

/***
 * Function getSeatSold: The function prompts the user for the seat being sold.
 */
void getSeatSold(int &row, int &seat)
{
    cout << "Enter the row: ";
    cin >> row;
    cin.ignore();
    cout << "Enter the seat: ";
    cin >> seat;
    cin.ignore();
}

/***
 * Function checkSeatSold: The function validates if the seat being sold is relevant.
 * That is if the seat number is valid, then returns true. Otherwise, returns false.
 */
bool checkSeatSold(int row, int seat)
{
    if (row > NUM_ROWS || row <= 0)
        return false;
    if (seat > NUM_SEATS || seat <= 0)
        return false;
    return true;
}

/***
 * Function checkSeatAvailable: The function checks if the seat is available or not.
 * If it is available, then returns true. Otherwise, returns false.
 */
bool checkSeatAvailable(const bool seats[][NUM_SEATS], int numRows, int row, int seat)
{
    // If the seat is not available, then return false.
    if (seats[row - 1][seat - 1] == false)
        return false;
    // Otherwise return true.
    return true;
}

/***
 * Function calculateTotalSales: The function calculates the total sales of all rows.
 */
double calculateTotalSales(const double rowSales[], int NUM_ROWS)
{
    double total = 0;

    for (int count = 0; count < NUM_ROWS; count++)
    {
         total += rowSales[count];
    }

    return total;
}

/***
 * Function displayLogging: The function displays a report showing how many seats have been
 * sold, how many seats are available, and how many seats are available in each row.
 */
void displayReport(const bool seats[][NUM_SEATS], int numRows)
{
    int totalSoldSeats = 0;         // The total of sold seats.
    int totalAvailableSeats = 0;    // The total of available seats.
    int availableSeats[numRows];    // The available seats in each row.
    for (int &row : availableSeats)
    {
        row = 0;
    }

    // Scan the array of seats.
    for (int row = 0; row < numRows; row++)
    {
        for (int seat = 0; seat < NUM_SEATS; seat++)
        {
            // If the seat had been sold.
            if (seats[row][seat] == false)
            {
                totalSoldSeats++;
            }
            // If the seat has not been sold.
            else if (seats[row][seat] == true)
            {
                totalAvailableSeats++;
                availableSeats[row]++;
            }
        }
    }
    
    cout << "--- REPORT ---\n";
    // Display the total seats that has been sold:
    cout << "Total sold seats: " << totalSoldSeats << endl;

    // Display the total available seats in the entire auditorium.
    cout << "Total available seats: " << totalAvailableSeats << endl;

    // Display the available seats in each row.
    cout << "Row\t" << "Seat available\n";
    for (int row = 0; row < numRows; row++)
    {
        cout << (row + 1) << "\t" << availableSeats[row] << endl;
    }
}

/***
 * Function getRowPrices. The function reads the prices of each row from
 * a file.
 */
void getRowPrices(double rowPrices[], int numRows, string fileName)
{
    // Open the file.
    ifstream inputFile;
    inputFile.open(fileName);

    // Check if the file was open successfully.
    if (inputFile.fail())
    {
        cout << "Error. Could not open file named " << fileName << endl;
    }

    // Read the data into the array.
    int count = 0;  // Loop counter.
    while (count < numRows && inputFile >> rowPrices[count])
    {
        count++;
    }

    // Close the file.
    inputFile.close();
}