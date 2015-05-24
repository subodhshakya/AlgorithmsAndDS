#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> listOfExclusion;

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(string initialNumber, string word, int a, int n)
{
	if (a == n)
	{
		cout << initialNumber << word << endl;
	}
	else
	{
		for (int j = a; j <= n; j++)
		{
			swap(&word[a], &word[j]);
			permute(initialNumber, word, a + 1, n);
			swap(&word[a], &word[j]); // back track
		}
	}
}

int main()
{
	listOfExclusion = {"2","6","8"};
	string initialNumber = "4";
	string word;
	for (int i = 0; i < 10; i++)
	{
		if ((find(listOfExclusion.begin(), listOfExclusion.end(), to_string(i)) == listOfExclusion.end()) && (initialNumber!=to_string(i)))
		{			
			word += to_string(i);
		}
	}
	permute(initialNumber, word, 0, word.size()-3);
}