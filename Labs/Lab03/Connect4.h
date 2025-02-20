#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace oopl {

    class C4Board {
        private:
        std::string grid; // Private field to represent the game grid
        int player; // Private field to represent the current player

        public: 
        static const std::string discs; // Public static constant field for player discs 

        // Default constructor 
        C4Board(){
            //Initialize grid with 42 asterisks and play to 0
            grid = std::string(42, '*');
            player = 0; 
        }

        // Copy constructor 
        C4Board(const C4Board& other){
            // Copy the grid and player from the other instance
            grid = other.grid;
            player = other.player;
        }

        // Assignment operator
        C4Board& operator=(const C4Board& other) {
            // Check for self-assignment 
            if (this != &other) {
                grid = other.grid; // Copy the grid 
                player = other.player; // Copy the player
            }

            return *this; // Return the current instance
        }

        // Destructor 
        ~C4Board() {

            // Empty destructor
    }

    // Method to get the current player 
    // Returns the current player (range [1,3])
    int current() const {
        return player; // Return the current player 
    }

    // Method to get the value at a specific index 
    // Returns the grid element at the specified index if valid, otherwise returns '*'
    char value(int index) const {
        if (index >=0 && index < 42) {
            return grid[index]; // Return the grid element at the index
        }
        return '*'; // Return '*' if index is out of range 
    }
}; 

// Initialize the static constant field 
const std::string C4Board::discs = "OXS";

} // namespace oopl
#endif // CONNECT4_H