/*
Write a method to decide if two strings are anagrams or not
*/

#include<iostream>
#include<string>

using namespace std;

bool AreAnagrams(string a, string b)
{
	int charCount_A[256] = {0};
	int charCount_B[256] = {0};
	if (a.length() != b.length())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			charCount_A[(int)a[i]]++;
			charCount_B[(int)b[i]]++;
		}
		bool areAnagram = true;
		for (int i = 0; i < a.length(); i++)
		{
			int asciiVal = (int)a[i];
			if (charCount_A[asciiVal] != charCount_B[asciiVal])
			{
				areAnagram = false;
				break;
			}
		}
		return areAnagram;
	}	
}

int main()
{
	string a, b;
	cout << "Enter first word: ";
	cin >> a;
	cout << "\nEnter second word: ";
	cin >> b;
	if (AreAnagrams(a, b))
	{
		cout << "Are anagrams!" << endl;
	}
	else
	{
		cout << "Not anagrams!" << endl;
	}
}