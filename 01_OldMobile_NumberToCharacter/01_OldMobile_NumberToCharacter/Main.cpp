/*
write a prog/method to convert number to character (as in old mobile phone).
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string inputStr;
	char pastChar;
	getline(cin, inputStr);	
	int length = 1;
	pastChar = inputStr[0];
	string outputStr = "";
	static char *hashMap[] = { "000", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	for (int i = 1; i <= inputStr.length(); i++)
	{
		char currentChar;
		// Check if array out of bound
		if (i < inputStr.length())
		{
			currentChar = inputStr[i];
		}
		else
		{
			currentChar = '\0';		// array out of bound means end of string processing
		}
		// check if current character match with previous character, if it does, increment the length by 1
		if (currentChar == pastChar || pastChar== '#')
		{
			length++;
			if (pastChar == '#')
				length = 1;
			pastChar = currentChar;
		}	
		else // if current character doesn't match the past character then process previous character to get mapping
		{
			int pastCharInt = pastChar - '0';
			outputStr += hashMap[pastCharInt - 1][length-1];
			length = 1;
			pastChar = currentChar;
		}
		// if '#' encountered then leave space
		if (currentChar == '#')
		{
			outputStr += ' ';
			pastChar = currentChar;			
		}
	}
	cout << outputStr<<endl;
}