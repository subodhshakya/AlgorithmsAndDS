/*
This is on Additive Number Property

Additive Number examples:
123459 (1+2=3, 4+5=9)
314538 (3+1=4, 5+3=8)
122436 (12+24=36)
You are given a range, you need to print all the additive numbers.
*/
#include<iostream>
#include<string>

using namespace std;

// This is recursive function
bool IsAdditiveNumber(string num, int offset)
{
	// base case
	if (offset>(num.length()/3))
	{
		return false;
	}
	int length = num.size();
	if (length % 3 != 0)
	{
		return false;
	}
	bool isAdditiveNo = true;	
	int count = 0;
	while (count < num.length())
	{
		int a = atoi((num.substr(count, offset)).c_str());
		count += offset;
		int b = atoi((num.substr(count, offset)).c_str());
		count += offset;
		int result = atoi((num.substr(count, offset)).c_str());
		count += offset;
		if (result != a + b)
		{
			offset++;
			//if in offset == 1 fails then again it tries with offset == 2 (i.e. considering 2 digits) and so on.
			return IsAdditiveNumber(num, offset);			
		}		
	}
	return isAdditiveNo;
}

void PrintAdditiveNumbers(string start, string end)
{
	int istart = atoi(start.c_str());
	int iend = atoi(end.c_str());
	for (int i = istart; i <= iend; i++)
	{
		string currentNo = to_string(i);
		if (IsAdditiveNumber(currentNo,1))
		{
			cout << currentNo << endl;
		}
	}
}

int main()
{
	string startNumber;
	string endNumber;
	cout << "Enter starting number of range: ";
	cin >> startNumber;
	cout << "Enter ending number of range: ";
	cin >> endNumber;
	PrintAdditiveNumbers(startNumber, endNumber);
}