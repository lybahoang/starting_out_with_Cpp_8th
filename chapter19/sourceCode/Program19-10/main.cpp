// This program displays a solution to the Towers of Hanoi game.
#include <iostream>
using namespace std;

// Function prototype.
void moveDics(int, int, int, int);

int main()
{
    const int NUM_DICS = 3;     // Number of discs to move.
    const int FROM_PEG = 1;     // Initial "from" peg.
    const int TO_PEG = 3;       // Initial "to" peg.
    const int TEMP_PEG = 2;     // Initial "temp" peg.

    // Play the game.
    moveDics(NUM_DICS, FROM_PEG, TO_PEG, TEMP_PEG);
    cout << "All the pegs are moved!\n";

    return 0;
}

/**
 * Function moveDiscs: Displays a disc move in the Towers of
 * Hanoi game.
 * @param num: The number of dics to move.
 * @param fromPeg: The peg to move from.
 * @param toPeg: The peg to move to.
 * @param tempPeg: The temporary peg.
 */
void moveDics(int num, int fromPeg, int toPeg, int tempPeg)
{
    if (num > 0)
    {
        // Move n - 1 dics from fromPeg to tempPeg using toPeg as
        // a temporary peg.
        moveDics(num - 1, fromPeg, tempPeg, toPeg);
        // Move the remaining dics from fromPeg to toPeg.
        cout << "Move a disc from peg " << fromPeg
             << " to peg " << toPeg << endl;
        // Move n - 1 dics from tempPeg to toPeg, using fromPeg as
        // a temporary peg.
        moveDics(num - 1, tempPeg, toPeg, fromPeg);
    }
}