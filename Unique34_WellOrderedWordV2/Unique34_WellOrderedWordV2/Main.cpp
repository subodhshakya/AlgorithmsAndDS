/*
A string "aBIY" is said to be a well-ordered word as each of the letters are in sequential manner regardless of case. 
So, "AbLe" is not a well-ordered word. You are a anti-hacker. you have a number of character sequences. 
Your task is to generate all possible well-ordered word that can be generated by those numbers of given character sequences.
*/

#include<iostream>
#include<string>

using namespace std;

void printWellOrdered(string word, int prev, int n)
{
	if (n == 0)
	{
		cout << word << endl;
		return;
	}

	for (int i = (prev + 1); i <= (27 - n); i++)
	{
		printWellOrdered(word + (char)(i + 96), i, n - 1);
		printWellOrdered(word + (char)(i + 64), i, n - 1);
	}
}

int main()
{
	int length;
	cout << "Enter length of well ordered string: ";
	cin >> length;
	printWellOrdered("", 0, length);
}