/*
Implement an algorithm to determine if a string has all unique characters  What if
you can not use additional data structures?

Solution below is for "What if
you can not use additional data structures?"
*/
#include<iostream>
#include<string>

using namespace std;

bool IsUnique(string word)
{
	int checker = 0;
	bool isUnique = true;
	for (int i = 0; i < word.length(); i++)
	{
		int asciiVal = (int)word[i];
		asciiVal = asciiVal - 'a';
		int leftShift = 1 << asciiVal;
		if ((checker & leftShift) != 0)
		{
			isUnique = false;
			break;
		}
		else
		{
			checker |= leftShift;
		}
	}	
	return isUnique;
}

int main()
{
	//test();
	string word;
	cout << "Enter a word: ";
	cin >> word;
	if (IsUnique(word))
	{
		cout << "All char unique" << endl;
	}
	else
	{
		cout << "All char are not unique" << endl;
	}
}