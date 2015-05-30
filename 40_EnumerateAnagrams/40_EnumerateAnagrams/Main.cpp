/*
Enumerate all possible anagrams of a random string where capital letters, numbers, 
and symbols are not allowed to move within the string.
*/

#include<iostream>
#include<string>

using namespace std;

void anagram(string &word, int n)
{
	if (n <= 0) {
		cout << word << "\n";
		return;
	}

	if (word[n] < 'a' || word[n] > 'z') {
		anagram(word, n - 1);
		return;
	}

	int i;
	for (i = n; i >= 0; --i) {
		if (word[i] < 'a' || word[i] > 'z')
			continue;

		char tmp = word[i];
		word[i] = word[n];
		word[n] = tmp;
		anagram(word, n - 1);
	}
}

int main()
{
	string inputStr = "drMaw12L";
	anagram(inputStr, inputStr.length()-1);
}