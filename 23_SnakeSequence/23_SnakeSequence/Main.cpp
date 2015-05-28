#include<iostream>
#include<vector>
#include<string>

using namespace std;

class SnakeData
{
public:
	int maxLength;
	int maxIndex;
};

string getRiseSnake(int arr[], int maxIndex)
{
	vector<int> snakeSequence;	
	//snakeSequence.push_back(arr[maxIndex]);
	int lastIndex = 0;
	int currentElm = arr[maxIndex];
	snakeSequence.push_back(currentElm);
	for (int i = maxIndex - 1; i >= 0; i--)
	{		
		if (arr[i]== currentElm + 1)
		{
			snakeSequence.push_back(arr[i]);
			currentElm = arr[i];
		}
	}
	/*if (lastIndex == 1 && (arr[0] + 1 == arr[1] || arr[0] == arr[1] + 1))
	{
		snakeSequence.push_back(arr[0]);
	}*/
	string seq;
	for (int i = snakeSequence.size()-1; i >= 0; i--)
	{		
		seq+= snakeSequence[i] + ",";
	}
	return seq;
}

string getFallSnake(int arr[], int maxIndex)
{
	vector<int> snakeSequence;
	//snakeSequence.push_back(arr[maxIndex]);
	int lastIndex = 0;
	int currentElm = arr[maxIndex];
	snakeSequence.push_back(currentElm);
	for (int i = maxIndex - 1; i >= 0; i--)
	{
		if (arr[i] == currentElm - 1)
		{
			snakeSequence.push_back(arr[i]);
			currentElm = arr[i];
		}
	}
	/*if (lastIndex == 1 && (arr[0] + 1 == arr[1] || arr[0] == arr[1] + 1))
	{
	snakeSequence.push_back(arr[0]);
	}*/
	string seq;
	for (int i = snakeSequence.size() - 1; i >= 0; i--)
	{
		seq += snakeSequence[i] + ",";
	}
	return seq;
}

SnakeData snakeUp(int arr[], int n)
{
	int lis[15];
	for (int i = 0; i < n; i++)
	{
		lis[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((arr[i] == arr[j]+1) && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	// Pick max
	int max = 0;
	int maxIndex = 0;
	SnakeData sd;
	for (int i = 0; i < n; i++)
	{
		if (max<lis[i])
		{
			sd.maxLength = lis[i];
			sd.maxIndex = i;
		}
	}
	return sd;
}

SnakeData snakeDown(int arr[], int n)
{
	int lis[15];
	for (int i = 0; i < n; i++)
	{
		lis[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((arr[i] == arr[j] -1 ) && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	// Pick max
	int max = 0;
	int maxIndex = 0;
	SnakeData sd;
	for (int i = 0; i < n; i++)
	{
		if (max<lis[i])
		{
			sd.maxLength = lis[i];
			sd.maxIndex = i;
		}
	}
	return sd;
}

int main()
{
	int arr[15] = { 1,3,2,6,8,-9,7,1,-1,2,1,5,0,1,9 };
	int arrRev[15];
	for (int i = 0; i < 15; i++)
	{
		arrRev[i] = arr[14 - i];
	}
	SnakeData up = snakeUp(arr, 15);
	SnakeData down = snakeDown(arrRev, 15);
	int downMaxIndex = 14 - down.maxIndex;
	string seq;
	if (downMaxIndex == up.maxIndex + 1)
	{
		seq = getRiseSnake(arr, up.maxIndex) + getFallSnake(arrRev, up.maxIndex);
		cout << seq;
	}
	else
	{
		if (up.maxLength>down.maxLength)
		{
			string seq1 = getRiseSnake(arr, up.maxIndex);
			string seq2 = getFallSnake(arr, up.maxIndex);
			cout << seq1 + seq2;
		}
		else
		{
			string seq1 = getFallSnake(arr, 14-down.maxIndex);
			string seq2 = getRiseSnake(arrRev, 14 - down.maxIndex);
			cout << seq1 + seq2;
		}
	}	
}