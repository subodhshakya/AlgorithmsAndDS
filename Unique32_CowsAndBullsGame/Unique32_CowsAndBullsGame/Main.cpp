/*
The cows and bulls game, Player A chooses a word and player B guesses a word. You say bulls when a character in 
the player B's guess match with a character in player A's word and also it is in the corect position as in A's word. 
You say cows, when a character in the player B's word match the character in player A, but it is not in the correct position. 
The characters are case insensitive. Given two words player A's and player B's,Write a function that return the number of bulls 
and no of cows. For example,
A - Picture B- Epic, bulls -0, cows - 4
A - forum B - four, bulls - 3 cows - 1
*/

#include<iostream>
#include<map>
#include<string>

using namespace std;

class Count
{
public:
	int bulls;
	int cows;
};

Count GetCount(string A_word, string B_word)
{
	map<char,int> a_wordCharIndexMap;
	Count c;
	int bullCount = 0;
	int cowCount = 0;
	// insert into hashset for linear searchtime
	for (int i = 0; i < A_word.length(); i++)
	{
		a_wordCharIndexMap[toupper(A_word[i])] = i;		
	}

	for (int j = 0; j < B_word.length(); j++)
	{
		char searchChar = toupper(B_word[j]);
		auto got = a_wordCharIndexMap.find(searchChar);
		if (got != a_wordCharIndexMap.end())
		{
			//found
			int a_index = a_wordCharIndexMap[searchChar];
			if (a_index == j)
			{
				bullCount++;
			}
			else
			{
				cowCount++;
			}
		}
	}
	c.bulls = bullCount;
	c.cows = cowCount;
	return c;
}

int main()
{
	Count c;
	string a1 = "forum";
	string b1 = "four";
	c = GetCount(a1, b1);
	cout << "A - " << a1 << " B - " << b1 << " bulls -" << c.bulls << ", cows -" << c.cows << endl;
	a1 = "Picture";
	b1 = "Epic";
	c = GetCount(a1, b1);
	cout << "A - " << a1 << " B - " << b1 << " bulls -" << c.bulls << ", cows -" << c.cows << endl;
}