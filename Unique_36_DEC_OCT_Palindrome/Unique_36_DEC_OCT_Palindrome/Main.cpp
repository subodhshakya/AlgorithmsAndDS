/*
The decimal and octal values of some numbers are both palindromes sometimes. Find such numbers within given range.
*/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool IsPalindrome(string input)
{
	int left = 0;
	int right = input.length() - 1;
	bool isPalindrome = true;
	while (left < right)
	{
		if (input[left] != input[right])
		{
			isPalindrome = false;
			break;
		}			
		left++;
		right--;
	}
	return isPalindrome;
}

void PrintPalindrome_DecOct( int start, int end)
{
	string decNumberStr;
	string octNumberStr;
	
	for (int i = start; i <= end; i++)
	{		
		stringstream ss;
		decNumberStr = to_string(i);
		ss << oct << i;
		octNumberStr = ss.str();
		if (IsPalindrome(decNumberStr) && IsPalindrome(octNumberStr))
		{
			cout << i << ",";
		}
	}	
	cout << endl;
}

int main()
{
	int start, end;
	cout << "Enter Start: ";
	cin >> start;
	cout << "Enter End: ";
	cin >> end;
	PrintPalindrome_DecOct(start, end);
}