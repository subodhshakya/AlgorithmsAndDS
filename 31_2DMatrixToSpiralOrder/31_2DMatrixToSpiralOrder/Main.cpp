/*
2D matrix to spiral order conversion
*/
#include<iostream>
#include<vector>
using namespace std;

int const N = 5;

void MatrixToSpiral(int ary[][N],int rowCount,int columnCount)
{
	int xTop = 0;
	int xDown = N-1;
	int yLeft = 0;
	int yRight = N-1;
	int count = 0;
	while (count < (rowCount*columnCount))
	{
		for (int i = yLeft; i <= yRight; i++)
		{
			cout << ary[xTop][i] << ",";
			count++;
		}
		xTop++;
		for (int i = xTop; i <= xDown; i++)
		{
			cout << ary[i][yRight] << ",";
			count++;
		}
		yRight--;
		for (int i = yRight; i >= yLeft; i--)
		{
			cout << ary[xDown][i] << ",";
			count++;
		}
		xDown--;
		for (int i = xDown; i >= xTop; i--)
		{
			cout << ary[i][yLeft] << ",";
			count++;
		}
		yLeft++;		
	}
}

int main()
{
	/*int aryInt[N][N] = { 
		{ 1, 9, 21, 13 },
		{ 3, 7, 8, -1 },
		{ 13, 5, 2, 1 },
		{ 5, -7, 3, 6 }
	};*/
	int aryInt[N][N] = {
		{ 1, 9, 21, 13,42 },
		{ 3, 7, 8, -1,67 },
		{ 13, 5, 2, 1,87 },
		{ 5, -7, 3, 6,99 },
		{ 8, -88, 7, 45, 73 }
	};
	MatrixToSpiral(aryInt, N, N);
}