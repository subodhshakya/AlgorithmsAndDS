/*
Given a sorted array with only 0's and 1's.Count the number of 0's.
e.g: 0 0 0 0 1 1
*/

#include<iostream>

using namespace std;

int const MAX_SIZE = 10;

int CountZero(int sortedAry[], int n)
{
	int l = 0;
	int r = n - 1;

	// Binary search (as array is sorted!!!)
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (sortedAry[m] < 1)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}

	return l;
}

int main()
{
	int ary[MAX_SIZE] = {0,0,0,0,0,0,0,0,1,1};
	cout << "Count: " << CountZero(ary, MAX_SIZE)<<endl;
}