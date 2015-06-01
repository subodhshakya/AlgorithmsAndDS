/*
The stepping number:
A number is called as a stepping number if the adjacent digits are having a difference of 1. 
For eg. 8,343,545 are stepping numbers. While 890, 098 are not. The difference between a ‘9’ and ‘0’ should not be considered as 1.
Given start number(s) and an end number(e) your function should list out all the stepping numbers in the range including both 
the numbers s & e.
*/
#include<iostream>
#include<string>

using namespace std;

void PrintSteppingNumbers(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		string number = to_string(i);
		if (number.length() == 1)
		{
			cout << number << ",";
		}
		else
		{
			bool isStepping = true;
			int previous = number[0] - '0';
			for (int j = 1; j < number.length(); j++)
			{
				int currentNumber = number[j] - '0';
				if (abs(currentNumber - previous) != 1)
				{ 
					isStepping = false;
				}
				previous = currentNumber;
			}
			if (isStepping)
			{
				cout << number<<",";
			}
		}
	}
	cout << endl;
}

int main()
{
	int start, end;
	cout << "Start: ";
	cin >> start;
	cout << "End: ";
	cin >> end;
	PrintSteppingNumbers(start, end);
}