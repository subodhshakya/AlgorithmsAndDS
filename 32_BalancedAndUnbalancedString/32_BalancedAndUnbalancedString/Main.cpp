/*
Balanced String
Given a string that has{},[],() and characters.Check if the string is balanced. E.g. {a[(b)]} is balanced. {a[(b])} isunbalanced.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BracketStack
{
private:
	vector<char> stack;
public:
	void push(char bracket)
	{
		stack.push_back(bracket);
	}

	char pop()
	{
		char topData = stack.back();
		stack.pop_back();
		return topData;
	}
};

bool IsBalanced(string inputStr)
{
	BracketStack bs;
	for (int i = 0; i < inputStr.size(); i++)
	{
		char currentChar = inputStr[i];
		if (currentChar == '[' || currentChar == '{' || currentChar == '(')
		{
			bs.push(currentChar);
		}
		else if (currentChar == ']' || currentChar == '}' || currentChar == ')')
		{
			char topBracket = bs.pop();
			switch (currentChar)
			{
			case ']':
				if (topBracket != '[')
					return false;
				break;
			case '}':
				if (topBracket != '{')
					return false;
				break;
			case ')':
				if (topBracket != '(')
					return false;
				break;
			default:
				break;
			}
		}
	}
	return true;
}

int main()
{
	string inputStr;
	cout << "Enter a string to test if it is balanced: ";
	cin >> inputStr;
	if (IsBalanced(inputStr))
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "Not balanced" << endl;
	}
}