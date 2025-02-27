#include <iostream> 
#include <string>
#include <cctype>

// Fuction: HasMove 
// Pseudocode:
// 1. Iterate though each character in the grid. 
// 2. If a blank character ('') is found, return true. 
// 3. If no blank character is found, return false. 
bool HasMove(const std::string& grid) {
    for (char cell : grid) {
        if (cell == ' ') {
            return true; 
        }
    }
    return false; 
}

// Function: ColumnWin
// Pseudocode: 
// 1. Iterate through each column (0 to 6).
// 2. For each column, check vertically for 4 consective discs of the same type (not '').
// 3. If such a sequence is found, return true. 
// 4. If no winning column is found, return false. 
bool Columnwin(const std:: string& grid) {
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            char current = grid[col + row * 7]; 
            if (current != ' ' &&
            current == grid[col + (row + 1) * 7] && 
            current == grid[col + (row + 2) * 7] && 
            current == grid[col + (row + 3) * 7]) {
                return true; 
            }
        }
    }
    return false; 
}

// Function: Populate 
// Pseudocode: 
// 1. Check if the column index is valid (bewtween 0 and 6 inclusively). 
// 2. Iterate from the bottom of the column (highest row index) to the top. 
// 3. If a blank character ('') is found, place the disc (character parameter) there and return true. 
// 4. If no space is found in the column, return false. 
bool Populate(std::string& grid, char disc, int column) {
    if (column <0 || column >= 7) {
        return false; // Invalid column index 
    }
    for (int row = 5; row >=0; --row) {
        int index = column + row * 7; 
        if (grid[index] == ' ' ){
            grid[index] = disc; 
            return true; 

        }
    }
    return false; // Column if fall 
}