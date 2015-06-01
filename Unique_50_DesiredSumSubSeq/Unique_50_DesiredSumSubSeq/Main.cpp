/*
1.Substring Addition
Write a program to add the substring
eg :say you have a list {1 7 6 3 5 8 9 } and user is entering a sum 16.Output should display (2-4) that is {7 6 3} cause 7+6+3=16.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Range
{
public:
	int start;
	int end;
};

vector<Range> FindRange(vector<int> seq, int targetSum)
{
	vector<Range> rangeList;
	bool found = false;
	for (int i = 0; i <seq.size(); i++)
	{
		int sum = 0;
		for (int j = i; j <seq.size(); j++)
		{
			sum += seq[j];
			if (sum == targetSum)
			{
				found = true;
				Range range;
				range.start = i;
				range.end = j;
				rangeList.push_back(range);
				break;
			}
		}
	}
	return rangeList;
}

void Display(vector<int> data, vector<Range> rangeList)
{
	if (rangeList.size() == 0)
	{
		cout << "Not found" << endl;
	}
	for (int j = 0; j < rangeList.size(); j++)\
	{
		Range range = rangeList[j];
		if (range.start != -1 && range.end != -1)
		{
			cout << "Start index: " << range.start << endl;
			cout << "End index: " << range.end << endl;
			for (int i = range.start; i <= range.end; i++)
			{
				if (i == range.end)
				{
					cout << data[i] << endl;
				}
				else
				{
					cout << data[i] << ",";
				}
			}
		}		
	}
	
}

int main()
{
	int sum;
	vector<int> data = { 1, 7, 6, 3, 5, 8, 9 };
	cout << "Enter sum: ";
	cin >> sum;
	vector<Range> rangeList = FindRange(data, sum);
	Display(data, rangeList);	
}