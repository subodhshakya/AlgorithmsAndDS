/*
An array consist of elements whose difference is positive or negative 1. I have to find the given elements without using linear search.
Say
Int arr[]={1,2,3,4,3,4,5,6,7 }

To find : 6
.
Please provide some one code/algorithm for this problem.
*/

#include<iostream>

using namespace std;

int const MAX_SIZE = 10;

bool FindElement(int ary[], int n)
{
	int current = 0;
	int count = 1;
	bool visited[MAX_SIZE] = {false};
	visited[0] = true;
	bool found = false;
	if (ary[current] == n)
	{
		return true;
	}
	else
	{
		int absDiff = abs(n - current);
		while (found != true||count<MAX_SIZE)
		{
			int refIndex = current - absDiff;
			if (refIndex >= 0)
			{
				if (ary[refIndex]==)
			}
		}
	}
}

int main()
{

}