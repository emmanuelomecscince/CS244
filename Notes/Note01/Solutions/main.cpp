#include <iostream> 
#include <string> 

/*Tic-Tac-Toe
* Create a tic-tac-toe game.
* You must use control structures and functions 
*/

void display(std::string board)
{
<<<<<<< HEAD
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
=======
	for(int i = 0;i < 9;i += 1)
	{
		std::cout << board[i];

		if((i + 1) % 3 == 0)
		{
			std::cout << "\n";
		}
	}
}

bool move(int player,std::string& board,int coordinate)
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
				board[coordinate] = 'O';
			}
			return true;
		}
	}
	return false;
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

bool rowWinner(const std::string& board)
{
<<<<<<< HEAD
     for(int i = 0;i < 9;i += 3)
     {
          if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != '_')
          {
               return true;
          }
     }
     return false; 
=======
	for(int i = 0;i < 9;i += 3)
	{
		if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != '_')
		{
			return true;
		}
	}
	return false;
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

bool columnWinner(const std::string& board)
{
<<<<<<< HEAD
     for(int i = 0;i < 3;i += 1)
     {
          if(board[i] == board[i+3] && board[i+3] ==board[i+6] && board[i] != '_')
          {
               return true;
          }
     }
     return false;
=======
	for(int i = 0;i < 3;i += 1)
	{
		if(board[i] == board[i+3] && board[i+3] ==board[i+6] && board[i] != '_')
		{
			return true;
		}
	}
	return false;
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

bool diagonalWinner(const std::string& board)
{
<<<<<<< HEAD
     if(board[0] == board[4] && board[4] == board[8])
     {
          return board [0] != '_';
     }
     else if(board[2] == board[4] && board[4] == board[6])
     {
          return board[2] != '_';
     }
     return false;
=======
	if(board[0] == board[4] && board[4] == board[8])
	{
		return board[0] != '_';
	}
	else if(board[2] == board[4] && board[4] == board[6])
	{
		return board[2] != '_';
	}
	return false;
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

bool hasWinner(const std::string& board)
{
<<<<<<< HEAD
     return (rowWinner(board) || columnWinner(board) || diagonalWinner(board));
=======
	return (rowWinner(board) || columnWinner(board) || diagonalWinner(board));
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

void changePlayer(int& player)
{
<<<<<<< HEAD
     player = (player + 1) % 2;
=======
	player = (player + 1) % 2;
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

bool isFull(const std::string& board)
{
<<<<<<< HEAD
     for(int i = 0;i < 9;i += 1)
     {
          if(board[i] == '_')
          {
               return false; 
          }
     }
     return true; 
=======
	for(int i = 0;i < 9;i += 1)
	{
		if(board[i] == '_')
		{
			return false;
		}
	}
	return true;
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

bool canPlay(const std::string& board)
{
<<<<<<< HEAD
     return !(hasWinner(board) || isFull(board));
=======
	return !(hasWinner(board) || isFull(board));
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

void gameLoop()
{
<<<<<<< HEAD
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
=======
	std::string board = "_________";
	int player = 0;
	int c;

	while(true)
	{
		display(board);

		while(true)
		{
			std::cout << "Enter coordinate Player " << (player + 1) << ": ";
			std::cin >> c;
			if(move(player,board,c))
			{
				break;
			}
		}

		if(canPlay(board))
		{
			changePlayer(player);
		}
		else
		{
			break;
		}
	}
	display(board);
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
}

int main()
{
<<<<<<< HEAD
     gameLoop();
     return 0; 
}
=======
	gameLoop();
	return 0;
}
>>>>>>> b4f9204c171138ee2fcaf79aa20ad3f8bce5d4b9
