/*
A magic index in an array A[1..n-1] is defined to be an index such that A[i] = i.
Given a sorted array of distinct integers, write a method to find a magic index,
if one exists, in array A.
*/

#include<iostream>

using namespace std;

int FindMagicIndex(int A[], int left, int right, int length)
{
	
	if (right<left || left < 0 || right >= length)
	{
		return -1;
	}
	int m = (left + right) / 2;
	if (A[m] == m)
	{
		return m;
	}
	else
	{
		if (A[m] < m)
		{
			FindMagicIndex(A, m + 1, right,length);
		}
		else
		{
			FindMagicIndex(A, left, m - 1,length);
		}
	}
}

int main()
{
	int A[] = { -40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13 };
	cout << FindMagicIndex(A, 0, 10,11) << endl;
}