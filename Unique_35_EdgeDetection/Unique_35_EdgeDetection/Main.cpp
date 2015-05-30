/*
Edge Detection:
Two-dimensional array representation of an image can also be represented by a one-dimensional array of W*H size, 
where W represent row and H represent column size and each cell represent pixel value of that image. you are also given a 
threshold X. For edge detection, you have to compute difference of a pixel value with each of it's adjacent pixel and 
find maximum of all differences. And finally compare if that maximum difference is greater than threshold X. 
if so, then that pixel is a edge pixel and have to display it.
*/
#include<iostream>
#include<vector>
using namespace std;

bool meetThreshold(vector<int> image, int xMin, int xMax, int yMin, int yMax, int x, int y, int width, int threshold)
{
	int maxDiff = 0;
	for (int i = xMin; i <= xMax; i++)
	{
		for (int j = yMin; j <= yMax; j++)
		{
			if (i == x && j == y)
				continue;
			int diff = abs(image[i * width + j] - image[x*width + y]);
			if (diff > maxDiff)
			{
				maxDiff = diff;
			}			
		}
	}
	if (maxDiff > threshold)
	{
		return true;
	}
	return false;
}

vector<int> processEdge(vector<int> image, int width,int threshold)
{
	vector<int> output;
	int totalElementCount = image.size();
	int height = totalElementCount / width;
	for (int row = 0; row <= height-1; row++)
	{
		for (int col = 0; col <= width-1; col++)
		{
			int xMin, xMax, yMin, yMax;
			xMin = row == 0 ? 0 : row - 1;
			xMax = row == height-1 ? height-1 : row + 1;
			yMin = col == 0 ? 0 : col - 1;
			yMax = col == width-1 ? width-1 : col + 1;
			if (meetThreshold(image, xMin, xMax, yMin, yMax, row, col, width, threshold))
			{
				output.push_back(row*width+col);
			}
		}
	}

	return output;
}

int main()
{
	int width = 5;
	vector<int> image = {
		1, 1, 1, 1, 1,
		1, 9, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1 };
	vector<int> output = processEdge(image, width, 6);
}