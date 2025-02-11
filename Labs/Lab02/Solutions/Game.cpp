#include <string> //string 

/*Objective: Check if there is a winner in a column
 *Input: The grid as a string
 *Algorithm:
 *1. for each column, do 
 *	1. if the element of the third row is not blank, then
 *		2. from the third row to the first, do
 *			1. if elements in the current row and
 *			the three row below it have the same disc in 
 *			the same column, then 
 *				1. return true.
 *2. return false 
 */
bool ColumnWin(const std::string& grid)
{
	for(int i = 14;i <= 20;i += 1)
	{
		if(grid[i] != '*')
		{

			for(int j = i;j >= 0;j -= 7)
			{
				if(grid[j] == grid[j+7] && grid[j] == grid[j+14] && grid[j+21])
				{
					return true;
				}
			}
		}
	}
	return false;
}

/*Objective: Try to add a disc to the grid
 *Inputs: a position: integer, a disc: character, a grid: string 
 *Algorithm:
 *1. if the position is between 0 and 6 inclusively and 
 *   top of the selected column is blank, then
 *	1. find the first blank in the selected column 
 *		starting from the bottom of the column, change it 
 *		to the disc and then return true
 *2. return false
 */
bool Populate(std::string& grid,char disc,int col)
{
	if(col >= 0 && col <= 6 && grid[col] == '*') 
	{
		for(int i = 35+col;i >= col;i -= 7)
		{
			if(grid[i] == '*')
			{
				grid[i] = disc;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	return 0;
}
