/*
Assume you have a method isSubstring which checks if one word is a substring of
another  Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
only one call to isSubstring (i e , “waterbottle” is a rotation of “erbottlewat”)
*/

#include<iostream>
#include<string>

using namespace std;

bool IsSubstring(string s1, string s2)
{
	auto got = s1.find(s2);
	if (got != std::string::npos)
	{
		// found;
		return true;
	}
	return false;
}

bool IsRotation(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	string s1s1 = s1 + s1;
	return IsSubstring(s1s1, s2);
}

int main()
{
	string s1, s2;
	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;
	if (IsRotation(s1, s2))
	{
		cout << "second string is rotation of first" << endl;
	}
	else
	{
		cout << "Not rotation" << endl;
	}
}
