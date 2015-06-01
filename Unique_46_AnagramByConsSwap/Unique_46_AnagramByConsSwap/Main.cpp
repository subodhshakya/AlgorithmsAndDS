/*
You can swap only two consecutive elements. You have to show all steps to convert a string into another 
string (both strings will be anagrams of each other). E.g. GUM to MUG
*/

#include<iostream>
#include<string>

using namespace std;

void Convert(string a, string b)
{
	int n = a.length();
	int i = 0;
	while (i<n)
	{
		char currentChar = a[i];
		int j = i;
		while (currentChar != b[j])
		{
			j++;
		}
		while (j>i)
		{
			char temp = b[j];
			b[j] = b[j - 1];
			b[j - 1] = temp;
			j--;
		}
		i++;
	}
}

int main()
{
	string strA = "ACADBB123";
	string strB = "DC1BA32BA";
	Convert(strA, strB);
}