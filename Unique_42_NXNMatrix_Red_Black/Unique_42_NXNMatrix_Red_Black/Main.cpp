/*
N*N matrix is given with input red or black. You can move horizontally, vertically or diagonally. 
If 3 consecutive same color found, that color will get 1 point. So if 4 red are vertically then point is 2. 
Find the winner.
*/
#include<iostream>
#include<string>

using namespace std;

int const WIDTH = 12;
int const HEIGHT = 10;

string FindWinner(int board[][WIDTH])
{
	// consider RED = 1;
	// consider BLACK = 2;
	int redCount = 0;
	int blackCount = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			// Horizontal
			if (j < WIDTH - 2)
			{
				if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1)
				{
					redCount++;
				}
				else if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2)
				{
					blackCount++;
				}
			}

			// Vertical
			if (i < HEIGHT - 2)
			{
				if (board[i][j] == 1 && board[i+1][j] == 1 && board[i+2][j] == 1)
				{
					redCount++;
				}
				else if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2)
				{
					blackCount++;
				}
			}

			// Diagonal
			if ((j < WIDTH - 2) && (i < HEIGHT - 2))
			{
				if (board[i][j] == 1 && board[i + 1][j+1] == 1 && board[i + 2][j+2] == 1)
				{
					redCount++;
				}
				else if (board[i][j] == 2 && board[i + 1][j+1] == 2 && board[i + 2][j+2] == 2)
				{
					blackCount++;
				}
			}
		}
	}
	if (redCount > blackCount)
	{
		return "RED";
	}
	else
		return "BLACK";
}

int main()
{
	int board[HEIGHT][WIDTH] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 2, 2, 2, 2, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 }
	};
	cout << "Winner: " <<FindWinner(board) << endl;
}