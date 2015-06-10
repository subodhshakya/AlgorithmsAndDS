/*
Implement an algorithm to determine if a string has all unique characters  What if you
can not use additional data structures?
--> What if you cannot use additional data structures? Solution on next project.
*/
#include<iostream>
#include<string>

using namespace std;

bool IsAllUniqueChar(string word)
{
	bool characterFlag[256] = { 0 };
	bool isUnique = true;
	for (int i = 0; i < word.length(); i++)
	{
		int charAscii = (int)word[i];
		if (!characterFlag[charAscii])
		{
			characterFlag[charAscii] = true;
		}
		else
		{
			isUnique = false;
			break;
		}
	}
	return isUnique;
}

int main()
{
	string word;
	cout << "Enter a word: ";
	cin >> word;
	if (IsAllUniqueChar(word))
	{
		cout << "All characters unique!" << endl;
	}
	else
	{
		cout << "Not all characters are unique!" << endl;
	}
}