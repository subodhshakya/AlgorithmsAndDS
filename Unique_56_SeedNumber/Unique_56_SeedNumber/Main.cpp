/*
Find the seed of a number.
Eg : 1716 = 143*1*4*3 =1716 so 143 is the seed of 1716. find all possible seed for a given number.
*/
#include<iostream>
#include<string>

using namespace std;

void PrintSeedNumbers(int number)
{
	for (int i = 0; i <= number; i++)
	{
		string numberStr = to_string(i);
		int product = i;
		for (int j = 0; j < numberStr.length(); j++)
		{
			int digit = numberStr[j] - '0';
			product *= digit;
		}
		if (product == number)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	int number;
	cout << "Enter a number for which seed are to be displayed: ";
	cin >> number;
	PrintSeedNumbers(number);
}