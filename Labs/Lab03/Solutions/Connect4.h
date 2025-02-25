#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <string>
#include <sstream>

namespace oopl 
{
	class C4Board 
	{
		private:
		std::string grid;
		int player;
		static const std::string discs;

		public:
		C4Board() : grid(std::string(42,'*')), player(0) {}

		C4Board(const C4Board& obj)
		{
			grid = obj.grid;
			player = obj.player;
		}

		C4Board& operator=(const C4Board& rhs)
		{
			if(this != &rhs)
			{
				grid = rhs.grid;
				player = rhs.player;
			}
			return *this;
		}

		~C4Board() {}

		/*
		 * algorithm:
		 * 1. return 1 plus player
		 */
		int current() const {return (player + 1);}

		/*
		 * input: idx : integer
		 * algorithm:
		 * 1. if idx in [0,41], then return grid[idx]
		 * 2. else return '*'
		 */
		char value(int idx) const 
		{
			return (idx >= 0 && idx <= 41)?(grid[idx]):('*');
		}
		
		/*
		 * algorithm:
		 * 1. for i in [0,6], do
		 * 	1. if grid[i] not '*', then return false
		 * 2. return true
		 */
	       	bool full() const 
		{
			for(int i = 0;i < 7;i += 1)
			{
				if(grid[i] != '*')
				{
					return false;
				}
			}
			return true;
		}

		/*
		 * algorithm:
		 * 1. for i in [35,41], do
		 * 	1. if grid[i] not '*', then return false
		 * 2. return true
		 */
		bool empty() const 
		{
			for(int i = 35;i < 42;i += 1)
			{
				if(grid[i] != '*')
				{
					return false;
				}
			}
			return true;
		}

		/*
		 * input: idx : integer
		 * algorithm:
		 * 1. return idx in [0,6] and grid[idx] equ '*'
		 */
		bool space(int idx) const 
		{
			return (idx >= 0 && idx <= 6 && grid[idx] == '*');
		}

		/*
		 * algorithm:
		 * 1. assign (player + 1) mod 3 to player
		 */
		void next() 
		{
			player = (player + 1) % 3;
		}

		/*
		 * algorithm:
		 * 1. return discs[player]
		 */
		char disc() const {return discs[player];}

		/*
		 * input: idx : integer
		 * algorithm: 
		 * 1. if space(idx), then
		 * 	1. for i in [5,0], do
		 * 		1. if grid[7*i+idx] equ '*', then
		 * 			1. assign disc() to grid[7*i+idx]
		 * 			2. return true
		 * 2. return false
		 */
		bool set(int idx) 
		{
			if(space(idx))
			{
				for(int i = 5;i >= 0;i -= 1)
				{
					if(grid[7*i+idx] == '*')
					{
						grid[7*i+idx] = disc();
						return true;
					}
				}
			}
			return false;
		}

		/*
		 * algorithm:
		 * 1. assign string(42,'*) to grid
		 * 2. assign 0 to player
		 */
		void reset() 
		{
			grid = std::string(42,'*');
			player = 0;
		}

		/*
		 * algorithm:
		 * 1. sprint("  0 1 2 3 4 5 6\n")
		 * 2. for i in [0,41], do 
		 * 	1. if i mod 7 equ 0, then sprint(i / 7)
		 * 	2. sprint(" " + grid[i])
		 * 	3. if (i + 1) mod 7 equ 0, then sprint('\n')
		 * 3. return sprint outcome
		 */
		std::string toString() const 
		{
			std::stringstream out;
			
			out << "  0 1 2 3 4 5 6\n";

			for(int i = 0;i < 42;i += 1)
			{
				if(i % 7 == 0)
				{
					out << (i / 7);
				}
				out << " " << grid[i];

				if((i + 1) % 7 == 0)
				{
					out << "\n";
				}
			}
			return out.str();
		}

		std::ostream& operator<<(std::ostream& out,const C4Board& obj)
		{
			return out << obj.toString();
		}
	};

	const std::string C4Board::discs = "OXS";
}
#endif
