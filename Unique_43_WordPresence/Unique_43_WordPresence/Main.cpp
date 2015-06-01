/*
Find the presence of a given word in a given grid, word can be matched in any direction 
up-down, down-up, left-right, right-left, both diagonals up and down etc.
*/
#include<iostream>
#include<string>

using namespace std;

int const WIDTH = 10;
int const HEIGHT = 8;

bool IsWordPresent(char grid[][WIDTH], string word)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j< WIDTH; j++)
		{
			bool forwardFound = true;
			bool backwardFound = true;
			bool upwardFound = true;
			bool downwardFound = true;
			bool upDiagonalFound = true;
			bool downDiagonalFound = true;
			for (int k = 0; k<word.length(); k++)
			{

				// Horizontal
				if (j<(WIDTH - word.length()))
				{
					if (grid[i][j + k] != word[k])
					{
						forwardFound = false;
					}
					if (grid[i][j + (word.length() - k)] != word[k])
					{
						backwardFound = false;
					}
				}
				else
				{
					forwardFound = false;
					backwardFound = false;
				}

				// Vertical
				if (i<(HEIGHT - word.length()))
				{
					if (grid[i + k][j] != word[k])
					{
						downwardFound = false;
					}
					if (grid[i + (word.length() - k)][j] != word[k])
					{
						upwardFound = false;
					}
				}
				else
				{
					downwardFound = false;
					upwardFound = false;
				}

				// Diagonal
				if ((j<(WIDTH - word.length())) && (i<(HEIGHT - word.length())))
				{
					if (grid[i + k][j + k] != word[k])
					{
						downDiagonalFound = false;
					}
					if (grid[i + (word.length() - k)][j + (word.length() - k)] != word[k])
					{
						upDiagonalFound = false;
					}

				}
				else
				{
					downDiagonalFound = false;
					upDiagonalFound = false;
				}
				if (!forwardFound && !backwardFound && !upwardFound && !downwardFound && !upDiagonalFound && !downDiagonalFound)
				{
					break;
				}
			}
			if (forwardFound || backwardFound || upwardFound || downwardFound || upDiagonalFound || downDiagonalFound)
			{
				return true;
			}
		}
	}
}

int main()
{
	char wordGrid[HEIGHT][WIDTH] = {
		{ 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'a', 'e', 'e', 'e', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'e', 'p', 'e', 'e', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'e', 'e', 'p', 'e', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'e', 'e', 'e', 'l', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e' },
		{ 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e' }
	};

	if (IsWordPresent(wordGrid, "apple"))
	{
		cout << "Found!" << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
}