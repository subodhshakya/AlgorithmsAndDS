/*
get a string(word) from user, then make every possible permutation words.
Ex)intput: tree => output : tree, rtee, rete, reet, etre, eetr, eert, eter, eret, teer, reet
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> permutationList;

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(string word, int i, int n)
{
	int j;
	if (i == n)
	{		
		if(find(permutationList.begin(), permutationList.end(), word) == permutationList.end())
		{
			// word not found in permutation list so it is unique word; this need to be done if there are repeating character in word
			cout << word << endl;			
		}			
		permutationList.push_back(word);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			swap(&word[i], &word[j]);
			permute(word, i + 1, n);
			swap(&word[i], &word[j]); //backtrack
		}
	}
}

int main()
{
	string w;
	cout << "Enter a word: ";
	cin >> w;	
	permute(w, 0, w.size() - 1);
}