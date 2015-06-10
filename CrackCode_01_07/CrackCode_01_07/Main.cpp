/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column is set to 0
*/
#include<iostream>

using namespace std;

const int M = 8;
const int N = 6;

void ZeroOutRowsColumns(int grid[][N])
{
	int row[M] = { 0 };
	int column[N] = { 0 };

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == 0)
			{
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (row[i] == 1 || column[j] == 1)
			{
				grid[i][j] = 0;
			}
		}
	}
}

int main()
{
	int grid[M][N] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 0, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 2, 3, 4, 0, 6 },
		{ 1, 2, 3, 4, 5, 6 }
	};

	ZeroOutRowsColumns(grid);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << grid[i][j] << ",";
		}
		cout << endl;
	}
}