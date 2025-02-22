#include "C4Board.h" // Include the C4Board class definition 
#include <iostream> 

using namespace oopl;

// Function to check for a column win
bool ColumnWin(const C4Board& board) {
    // Pseudocode:
    // 1. Iterate through each column (o to 6). 
    // 2. For each column, check for 4 consecutive discs of the same type. 
    // 3. If found, return true. 
    // 4. If no column has a win, return false. 

    for(int col=0; col<7; ++col) {
        int count = 0;
        char currentDisc = '*'; 

        for (int row = 0; row < 6; ++row) {
            int index = row * 7 + col;
            char disc = board.value(index);

            if (disc != '*' && disc == currentDisc) {
                ++count;
                if (count == 3) { // 4 in a row (including the current disc)
                    return true; 
            }
        } else {
            count = 0; 
            currentDisc = disc; 
        }
    }
    return false; 
}

// Function to check for a row win 
bool RowWin(const C4Board& board) {
    // Pseudocode: 
    // 1. Iterate through each row (0 to 5).
    // 2. For each row, check for 4 consecutive discs of the same type. 
    // 3. If found, return true. 
    // 4. If no row has a win, return false. 

    for (int row = 0; row < 6; ++row) {
        int count = 0;
        char currentDisc = '*';

        for (int col = 0; col < 7; ++col) {
            int index = row * 7 + col;
            char disc = board.value(index);

            if(disc != '*' && disc == currentDisc) {
                ++count; 
                if (count == 3) { // 4 in a row (including the current disc)
                    return true; 
                }
            } else {
                count = 0;
                currentDisc = disc; 
            }
        }
    }
    return false; 
    
}
