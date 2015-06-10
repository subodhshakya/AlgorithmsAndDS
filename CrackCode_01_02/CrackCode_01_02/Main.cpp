/*
Write code to reverse a C-Style String  (C-String means that “abcd” is represented as
five characters, including the null character )
*/
#include<iostream>
#include<string>

using namespace std;

void Reverse(char *word)
{
	char * end = word;
	char temp;
	while (*end)
	{
		++end;
	}
	--end;
	while (word < end)
	{
		temp = *word;
		*word++ = *end;
		*end-- = temp;
	}
}

int main()
{
	char word[50];
	cout << "Enter a word: ";
	cin >> word;
	Reverse(word);
	cout << "Reverse: " << word << endl;
}