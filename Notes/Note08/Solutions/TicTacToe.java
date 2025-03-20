import java.util.Scanner;

class TicTacToe
{
	public static void display(char[] board)
	{
		for(int i = 0;i < 9;i += 1)
		{
			System.out.print(board[i]); //cout 

			if((i + 1) % 3 == 0)
			{
				System.out.println(); //cout << argument << "\n";
			}
		}
	}	

	public static boolean move(int player,char[] board,int coordinate)
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
	}

	public static boolean rowWinner(char[] board)
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

	public static boolean columnWinner(char[] board)
	{
		for(int i = 0;i < 3;i += 1)
		{
			if(board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != '_')
			{
				return true;
			}
		}
		return false;
	}

	public static boolean diagonalWinner(char[] board)
	{
		if(board[0] == board[4] && board[4] == board[8])
		{
			return board[0] != '_';
		}
		else if(board[2] == board[4] && board[4] == board[6])
		{
			return board[2] != '_';
		}
		return false;
	}

	public static boolean hasWinner(char[] board)
	{
		return (rowWinner(board) || columnWinner(board) || diagonalWinner(board));
	}

	public static int changePlayer(int player)
	{
		return (player + 1) % 2;
	}

	public static boolean isFull(char[] board)
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

	public static boolean canPlay(char[] board)
	{
		return !(hasWinner(board) || isFull(board));
	}

	public static void gameLoop()
	{
		Scanner cin = new Scanner(System.in);
		String init = "_________";
		char[] board = init.toCharArray();
		int player = 0;
		int c;

		while(true)
		{
			display(board);

			while(true)
			{
				System.out.print("Enter coordinate Player " + (player + 1) + ": ");
				c = cin.nextInt();
				
				if(move(player,board,c))
				{
					break;
				}
			}

			if(canPlay(board))
			{
				player = changePlayer(player);
			}
			else
			{
				break;
			}
		}
		display(board);
	}

	public static void main(String[] args)
	{
		gameLoop();
	}
}
