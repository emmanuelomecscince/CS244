#ifdef CONNECT4_H 
#define CONNECT4_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace oopl {

    class C4Board {
        private:
        std::string grid; // Represents the 6x7 grid as a single string of 42 characters 
        int player;       // Current player (0, 1 or 2)

        public: 
        static const std::string discs; // Discs for players: 'O','X','S' 

        // Default constructor 
        C4Board() : grid(42, '*'), player(0){}

        // Copy constructor 
        C4Board(const C4Board& other) : grid(other.grid), player(other.player) {}

        // Assignment operator
        C4Board& operator=(const C4Board& other) {
            if (this != &other) {
                grid = other.grid;
                player = other.player;
            }
            return *this; 
        }

        // Destructor
        ~C4Board() {}

        // Returns the current player (1, 2, or 3)
        int current() const {
            return player + 1; 
        }

        // Returns the grid element at the given index, or '*' if the index is invalid 
        char value(int index) const {
            if (index >=0 && index < 42) {
                return grid[index]; 
            }
            return '*', 
        }

        // Returns true if the grid is full (no asterisks), otherwise false 
        bool full() const {
            return grid.find('*') == std::string::npos; 
        }
        
        // Returns true if the grid is empty (all asterisks), otherwise false 
        bool empty() const {
            return grid.find_first_not_of('*')== std::string::npos; 
        }

        // Returns true if the column has available space, otherwise false 
        bool space(int col) const {
            if (col < 0 || col > 6) return false; 
            return grid[col] == '*';
        }

        // Switches to the next player 
        void next() {
            player = (player + 1) % 3; 
        }

        // Returns the disc of the current player 
        char disc() const {
            return discs[player]; 
        } 

        // Inserts the current player's disc into the specified column 
        bool set(int col) {
            if (col < 0 || col > 6 || !space(col)) return false;

            for (int row = 5; row >= 0; --row) {
                int index = row * 7 + col;
                if (grid[index] == '*') {
                    grid[index] = disc(); 
                    return true; 
                }
            }
            return false; 
        }

        // Resets the grid and player 
        void reset() {
            grid = std::string(42, '*');
            player = 0; 
        }

        // Returns a string representation of the grid 
        std::string toString() const {
            std::ostringstream oss; 
            for (int row = 0; row < 6; ++row) {
                for (int col = 0; col < 7; ++col) {
                    oss << std::setw(2) << grid[row * 7 + col]; 
                }
                oss << "\n";
            }
            return oss.str(); 
        }

        // Friend function to overload the << operator 
        friend std::ostream& operator<<(std::ostream& os, const C4Board& board) {
            os << board.toString();
            return os; 
        }
    }; 

    // Initialize the static member 
    const std::string C4Board::discs = "OXS"; 

} // namespace oopl 
#endif // CONNECT4_H 
