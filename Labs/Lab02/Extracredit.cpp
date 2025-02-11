#include <iostream>
#include <string>
#include <cctype>

// Function: DiagonalWin
// Pseudocode:
// 1. Iterate through each cell in the grid. 
// 2. For each cell, check diagonally (both left-down and right-down) for 4 consecutive discs of the same type (not ''). 
// 3. If such a sequence is found, return true. 
// 4. If no winning diagonal is found, return false. 
bool DiagonalWin(const std::string& grid) {
    // Check for diagonals with a positive slope (left-down to right-up)
    for(int row = 0; row <3; ++row) {
        for (int col = 0; col < 4; ++col) {
            char current = grid[col + row * 7];
            if (current != ' ' && 
            current == grid[col + 1 +(row + 1) * 7] && 
            current == grid[col + 2 + (row +2) * 7] && 
            current == grid[col + 3 + (row + 3) * 7]) {
                return true; 
            }
        }
    }

    // Check for diagonals with a negative slope (right-down to left-up)
    for (int row = 0; row < 3; ++row) {
        for (int col = 3; col < 7; ++col) {
            char current = grid[col + row * 7];
            if (current != ' ' &&
            current == grid[col - 1 + (row + 1) * 7] && 
            current == grid[col - 2 + (row + 2) * 7] && 
            current == grid[col - 3 + (row + 3) * 7]) {
                return true; 
            }
        }
    }

    return false; // No diagonal win found 

}