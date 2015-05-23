/*
Write a program for a word search. If there is an NxN grid with one letter in each cell. 
Let the user enter a word and the letters of the word are said to be found in the grid either 
the letters match vertically, horizontally or diagonally in the grid. If the word is found, print 
the coordinates of the letters as output.
*/
#include<iostream>
#include<vector>

using namespace std;
const int N = 5;

class Coordinate
{
public:
	int x;
	int y;
};

void DisplayVerticalCoordinates(char grid[][N], Coordinate* startCoordinate, int wordLength)
{
	int xpos = startCoordinate->x;
	int ypos = startCoordinate->y;
	for (int i = 0; i < wordLength; i++)
	{
		cout << "(" << xpos + i << "," << ypos << ")" << endl;
	}
}

void DisplayHorizontalCoordinates(char grid[][N], Coordinate* startCoordinate, int wordLength)
{
	int xpos = startCoordinate->x;
	int ypos = startCoordinate->y;
	for (int i = 0; i < wordLength; i++)
	{
		cout << "(" << xpos << "," << ypos + i << ")" << endl;
	}
}

void DisplayCrossCoordinates(char grid[][N], Coordinate* startCoordinate, int wordLength)
{
	int xpos = startCoordinate->x;
	int ypos = startCoordinate->y;
	for (int i = 0; i < wordLength; i++)
	{
		cout << "(" << xpos + i << "," << ypos + i << ")" << endl;
	}
}

void NXN_GridSearch(char grid[][N], string word, int size)
{
	vector<Coordinate*> firstCharacterCoordinates;
	char firstChar = word[0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (firstChar == grid[i][j])
			{
				Coordinate *cor = new Coordinate();
				cor->x = i;
				cor->y = j;
				firstCharacterCoordinates.push_back(cor);
			}
		}
	}

	bool found = false;
	// now check each of the possible coordinate
	for (int i = 0; i < firstCharacterCoordinates.size(); i++)
	{
		int currentX = firstCharacterCoordinates[i]->x;
		int currentY = firstCharacterCoordinates[i]->y;
		
		// check vertically
		found = true;
		for (int j = 0; j < word.length(); j++)
		{
			int xpos = currentX + j;
			if ((xpos > size - 1) || (word[j] != grid[xpos][currentY]))
			{
				found = false;
				break;
			}			
		}
		if (found)
		{
			DisplayVerticalCoordinates(grid, firstCharacterCoordinates[i], word.length());
			break;
		}
		// check horizontally
		found = true;
		for (int j = 0; j < word.length(); j++)
		{
			int ypos = currentY + j;
			if ((ypos > size - 1) || (word[j] != grid[currentX][ypos]))
			{
				found = false;
				break;
			}			
		}
		if (found)
		{
			DisplayHorizontalCoordinates(grid, firstCharacterCoordinates[i], word.length());
			break;
		}
		// check cross
		found = true;
		for (int j = 0; j < word.length(); j++)
		{
			int xpos = currentX + j;
			int ypos = currentY + j;
			if ((ypos > size - 1) || (xpos > size - 1) || (word[j] != grid[xpos][ypos]))
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			DisplayCrossCoordinates(grid, firstCharacterCoordinates[i], word.length());
			break;
		}
	}
}

int main()
{
	char grid[5][5] = {
		{ 'a', 'f', 'd', 'a', 'd' },
		{ 'b', 'c', 'a', 't', 'c' },
		{ 'c', 'g', 'm', 'i', 'a' },
		{ 'd', 'h', 'h', 'l', 'o' },
		{ 'e', 'h', 'a', 't', 'l' }
	};
	NXN_GridSearch(grid, "cat", 5);
}