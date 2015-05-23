/*
Annosance problem. Like you are given a string and you have to find words starting with a vowel and move that each word 
untill next to the previous vowel word ..
*/
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

class Assonance
{
public:		
	bool IsVowelWord(string p_word)
	{
		char startChar = p_word[0];
		switch (startChar)
		{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				return true;
				break;
			default:
				return false;
				break;
		}
	}

	string GetAssonanceString(string inputString)
	{
		string assonanceString;
		stringstream ss(inputString);
		ss >> ws;

		string token;		
			
		bool firstVowelWordOccured = false;
		int startMarker = -1;
		vector<string> vowelWordList;
		vector<string> nonVowelList;
		while (getline(ss, token, ' '))
		{
			if (IsVowelWord(token))
			{
				if (!firstVowelWordOccured)
				{					
					startMarker = nonVowelList.size() - 1;
					firstVowelWordOccured = true;
				}
				vowelWordList.push_back(token);
			}
			else
			{
				nonVowelList.push_back(token);
			}			
		}
		if (startMarker < 0)
		{
			for (int i = 0; i < vowelWordList.size(); i++)
			{
				assonanceString += vowelWordList[i] + " ";
			}
			for (int i = 0; i < nonVowelList.size(); i++)
			{
				assonanceString += nonVowelList[i] + " ";
			}
		}
		else
		{
			for (int i = 0; i <= startMarker; i++)
			{
				assonanceString += nonVowelList[i] + " ";
			}
			for (int i = 0; i < vowelWordList.size(); i++)
			{
				assonanceString += vowelWordList[i] + " ";
			}
			for (int i = startMarker + 1; i < nonVowelList.size(); i++)
			{
				assonanceString += nonVowelList[i] + " ";
			}
		}		
		return assonanceString;
	}
};

int main()
{
	Assonance asc;
	string sentence;
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	cout << asc.GetAssonanceString(sentence) << endl;
}