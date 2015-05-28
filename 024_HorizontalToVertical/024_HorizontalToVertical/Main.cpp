/*
24> given a horizontal array of strings convert it to vertical. like english characters are read left to right. convert them to a chinese format which is read vertically.
eg.
epic is a healthcare company.
interviewing for software developer.
print this vertically sentence by sentence.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void PrintHorizontalToVertical(vector<string> sentences, vector<int> lengths, int maxLength)
{
	for (int i = 0; i < maxLength; i++)
	{
		for (int j = 0; j < sentences.size(); j++)
		{
			if (i < lengths[j])
			{
				cout << sentences[j][i] << "\t";
			}
			else
			{
				cout << " " << "\t";
			}
		}
		cout << endl;
	}
}

int main()
{
	vector<string> sentences;
	vector<int> lengths;
	string inputStr;
	int maxLength = 0;
	getline(cin, inputStr);
	while (inputStr != "")
	{
		sentences.push_back(inputStr);
		int len = inputStr.length();
		if (len > maxLength)
			maxLength = len;
		lengths.push_back(len);
		getline(cin, inputStr);		
	}
	PrintHorizontalToVertical(sentences, lengths,maxLength);
}