#include <iostream>
using namespace std;

// Constants.
const int NUM_QUARTERS = 4;

// Structure declaration.
struct DivisionSales {
    string divisionName;    // The name of the division.
    double *sales;          // The array of the sales for each quarter.
    double totalSales;      // The total sales of the division.
    double averageSales;    // The average quarterly sales.
};

