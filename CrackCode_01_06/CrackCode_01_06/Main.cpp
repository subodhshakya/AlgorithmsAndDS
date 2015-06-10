/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees  Can you do this in place?
*/
#include<iostream>
#include<stdint.h>

const int N = 6;

using namespace std;

void Rotate(int32_t image[][N])
{
	for (int layer = 0; layer < N / 2; layer++)
	{
		int start = layer;
		int end = N - 1 - start;
		for (int j = start; j < end; j++)
		{
			int offset = j - start;
			// left top
			int top = image[start][j];

			// left down
			// RHS is decreasing from end to start row wise so offset is required when decreasing
			image[start][j] = image[end-offset][start];

			// right down
			image[end - offset][start] = image[end][end - offset];

			// RHS is increasing from start to end so no offset is required when increasing.
			image[end][end - offset] = image[j][end];

			image[j][end] = top;
		}
	}
}

int main()
{
	int32_t image[N][N] = {
		{ 0, 1, 2, 3, 4, 5},
		{ 10, 13, 24, 34, 44, 54},
		{ 50, 15, 25, 35, 45, 55},
		{ 60, 16, 26, 36, 46, 56},
		{ 70, 17, 27, 37, 47, 57},
		{ 80, 18, 28, 38, 48, 58}
	};
	Rotate(image);
	for (int i = 0; i < N; i++)
	{
		string lineOutput = "";
		for (int j = 0; j < N; j++)
		{
			if (j != N - 1)
			{
				cout << image[i][j] << ",";
			}
			else
			{
				cout << image[i][j];
			}
		}
		cout << endl;
	}
}