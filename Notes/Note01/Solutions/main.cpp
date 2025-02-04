#include <iostream> 
#include <string> 

/*Tic-Tac-Toe
* Create a tic-tac-toe game.
* You must use control structures and functions 
*/

void display(std::string board)
{
     for(int i = 0;i < 9;i += 1)
     {
          std:: cout << board[i];

          if((i + 1) % 3 == 0)
          {
               std::cout << "\n";
          }
     }
}

bool move(int player, std::string& board,int coordinate)
{
     if(coordinate >= 0 && coordinate <= 8)
     {
          if(board[coordinate] == '_')
          {
               if(player == 0)
               {
                    board[coordinate] = 'X';
               }
               else
               {
                    board[coordinate] = '0';
               }
               return true;
          }
     }
     return false;
}

bool rowWinner(const std::string& board)
{
     for(int i = 0;i < 9;i += 3)
     {
          if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != '_')
          {
               return true;
          }
     }
     return false; 
}

bool columnWinner(const std::string& board)
{
     for(int i = 0;i < 3;i += 1)
     {
          if(board[i] == board[i+3] && board[i+3] ==board[i+6] && board[i] != '_')
          {
               return true;
          }
     }
     return false;
}

bool diagonalWinner(const std::string& board)
{
     if(board[0] == board[4] && board[4] == board[8])
     {
          return board [0] != '_';
     }
     else if(board[2] == board[4] && board[4] == board[6])
     {
          return board[2] != '_';
     }
     return false;
}

bool hasWinner(const std::string& board)
{
     return (rowWinner(board) || columnWinner(board) || diagonalWinner(board));
}

void changePlayer(int& player)
{
     player = (player + 1) % 2;
}

bool isFull(const std::string& board)
{
     for(int i = 0;i < 9;i += 1)
     {
          if(board[i] == '_')
          {
               return false; 
          }
     }
     return true; 
}

bool canPlay(const std::string& board)
{
     return !(hasWinner(board) || isFull(board));
}

void gameLoop()
{
     std::string board = "_________"
     int player = 0; 
     int c;

     while(true)
     {
          display(board);

          while(true)
          {
               std::cout << "Enter coordinate Player " << ("player" + 1) << ": ";
               std::cin >> c;
               if(move("player",board,c))
               {
                    break;
               }
          }

          if (canPlay(board))
          {
               changePlayer(player);
          }
          else
          {
               break;
          }
     }
     display(board);
}

int main()
{
     gameLoop();
     return 0; 
}