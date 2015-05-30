/*
Jumper Game: A NxN grid which contains either of 0-empty, 1 - player1, 2 - player 2. Given a position in the grid, 
find the longest jump path. For jump path, you can horizontally or vertically, you can jump on opponent cell and 
also the landing cell should be empty. No opponent cell can be jumped more than once. Write a function which takes 
grid and a specific position in the grid, and returns the longest possible number of jumps in the grid.
*/
#include<iostream>

using namespace std;

int const GRID_DIMENSION = 10;

int GetLongestJump(int grid[][GRID_DIMENSION], int x, int y)
{
	int maxJumpCount = 0;	
	int currentJumpCount = 0;
	
	// Horizontal Right
	int currentX = x;
	int currentY = y;
	int currentPlayer = grid[x][y];
	while (currentY <= GRID_DIMENSION-1)
	{
		if (grid[x][currentY + 1] != 0 && (currentY + 2) <= GRID_DIMENSION - 1)
		{
			if (grid[x][currentY + 2] == 0 && grid[x][currentY + 1] != currentPlayer)
			{
				currentJumpCount++;
				break;
			}
			else if (grid[x][currentY + 2] == 0 && grid[x][currentY + 1] == currentPlayer)
			{
				currentJumpCount++;
				currentY += 2;
			}
		}
		else
		{
			break;
		}
	}
	
	if (currentJumpCount > maxJumpCount)
		maxJumpCount = currentJumpCount;

	// Horizontal Left
	currentX = x;
	currentY = y;
	currentPlayer = grid[x][y];
	currentJumpCount = 0;
	while (currentY >= 0)
	{
		if (grid[x][currentY - 1] != 0 && (currentY - 2) >= 0)
		{
			if (grid[x][currentY - 2] == 0 && grid[x][currentY - 1] != currentPlayer)
			{
				currentJumpCount++;
				break;
			}
			else if (grid[x][currentY - 2] == 0 && grid[x][currentY - 1] == currentPlayer)
			{
				currentJumpCount++;
				currentY -= 2;
			}
		}
		else
		{
			break;
		}
	}
	if (currentJumpCount > maxJumpCount)
		maxJumpCount = currentJumpCount;

	// Vertical Down
	currentX = x;
	currentY = y;
	currentPlayer = grid[x][y];
	currentJumpCount = 0;
	while (currentX <= GRID_DIMENSION - 1)
	{
		if (grid[currentX + 1][y] != 0 && (currentX + 2) <= GRID_DIMENSION - 1)
		{
			if (grid[currentX + 2][y] == 0 && grid[currentX + 1][y] != currentPlayer)
			{
				currentJumpCount++;
				break;
			}
			else if (grid[currentX + 2][y] == 0 && grid[currentX + 1][y] == currentPlayer)
			{
				currentJumpCount++;
				currentX += 2;
			}
		}
		else
		{
			break;
		}
	}
	
	if (currentJumpCount > maxJumpCount)
		maxJumpCount = currentJumpCount;

	// Vertical Up
	currentX = x;
	currentY = y;
	currentPlayer = grid[x][y];
	currentJumpCount = 0;
	while (currentX >= 0)
	{
		if (grid[currentX - 1][y] != 0 && (currentX - 2) >= 0)
		{
			if (grid[currentX - 2][y] == 0 && grid[currentX - 1][y] != currentPlayer)
			{
				currentJumpCount++;
				break;
			}
			else if (grid[currentX - 2][y] == 0 && grid[currentX - 1][y] == currentPlayer)
			{
				currentJumpCount++;
				currentX -= 2;
			}
		}
		else
		{
			break;
		}
	}
	
	if (currentJumpCount > maxJumpCount)
		maxJumpCount = currentJumpCount;

	return maxJumpCount;
}

int main()
{
	int grid[GRID_DIMENSION][GRID_DIMENSION] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 0, 0, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	cout << GetLongestJump(grid, 1, 1);
}