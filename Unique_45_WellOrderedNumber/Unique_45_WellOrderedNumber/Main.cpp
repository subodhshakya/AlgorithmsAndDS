/*
Given n. Generate all numbers with number of digits equal to n, such that the digit to the right is greater than 
the left digit (ai+1 > ai). E.g. if n=3 (123,124,125,……129,234,…..789)
*/
#include<iostream>
#include<string>

using namespace std;

void wellOrderedNumber(string word, int previous, int n)
{
	if (n == 0)
	{
		cout << word << endl;
		return;
	}

	for (int i = (previous + 1); i<(11 - n); i++)
	{
		char c = i + '0';
		wellOrderedNumber(word + c, i, n - 1);
	}
}

int main()
{
	int digitCount;
	cout << "Enter number of digits in number: ";
	cin >> digitCount;
	wellOrderedNumber("", 0, digitCount);
}