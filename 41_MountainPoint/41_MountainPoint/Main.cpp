/*
Given a M * N matrix, if the element in the matrix is larger than other 8 elements who stay around it, 
then named that element be mountain point. Print all the mountain points.
*/

#include<iostream>

using namespace std;
int const W = 10;
int const H = 12;

void PrintMountainPoints(int matrix[][W])
{
	for (int i = 1; i < H - 1; i++)
	{
		for (int j = 1; j < W - 1; j++)
		{
			bool isMountain = true;
			for (int k = j - 1; k <= j + 1; k++)
			{
				if (matrix[i - 1][k] > matrix[i][j] || matrix[i + 1][k] > matrix[i][j])
				{
					isMountain = false;
				}
			}			
			if (matrix[i][j - 1] > matrix[i][j] || matrix[i][j + 1] > matrix[i][j])
			{
				isMountain = false;
			}
			if (isMountain)
			{
				cout << "(" << i << "," << j << ") : " << matrix[i][j] << endl;
			}
		}		
	}
}

int main()
{
	int matrix[H][W] = {
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 5, 3, 9, 5, 15, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 85, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 21, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 33, 4, 5, 6, 7, 8, 99, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	};
	PrintMountainPoints(matrix);
}