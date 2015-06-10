/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer  NOTE: One or two additional variables are fine
An extra copy of the array is not
FOLLOW UP
Write the test cases for this method

Algorithm—With Additional Memory of Constant Size
*/
#include<iostream>
#include<string>

using namespace std;

string getNoDuplicateString(string word)
{
	bool hitFlag[256] = {false};
	int tail = 0;	
	for (int i = 0; i < word.length(); i++)
	{
		int asciiChar = (int)word[i];
		if (!hitFlag[asciiChar])
		{
			word[tail] = word[i];
			tail++;
			hitFlag[asciiChar] = true;
		}
	}	
	return word.substr(0, tail);
}

int main()
{
	string word;
	cout << "Enter a word: ";
	cin >> word;
	cout << "\n" << getNoDuplicateString(word) << endl;
}