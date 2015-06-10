/*
Write a method to replace all spaces in a string with ‘%20’
*/

#include<iostream>
#include<string>

using namespace std;

string ReplaceSpace(string sentence)
{
	string accumulate = "";
	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == ' ')
		{
			accumulate += "%20";
		}
		else
		{
			accumulate += sentence[i];
		}
	}
	return accumulate;
}

int main()
{
	string sentence;
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	cout << ReplaceSpace(sentence) << endl;
}