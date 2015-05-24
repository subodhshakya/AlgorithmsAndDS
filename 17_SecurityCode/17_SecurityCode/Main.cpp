/*
security code takes numbers but one key is allowed to be faulty, other numbers should be same in sequence 
ex 124 is accepted if actual number is 126 46..
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool Check(string enteredPwd, string expectedPwd, int diff)
{
	int enteredPwdPos = 0;
	int unmatchCount = 0;
	vector<char> missingCharacters;
	bool valid = true;
	for (int i = 0; i < expectedPwd.size(); i++)
	{
		if (enteredPwd[enteredPwdPos] == expectedPwd[i])
		{
			// current char is match, move to next char in entered password
			enteredPwdPos++;
		}
		else
		{
			// no match, increment unmatch count and collect unmatched character
			unmatchCount++;
			missingCharacters.push_back(expectedPwd[i]);
		}
	}
	if (unmatchCount != diff)
	{
		// if unmatch count and difference count is not same then it is invalid.
		valid = false;
		return valid;
	}
	else
	{
		// missing character count and length difference is same
		// now check if all missing character is same.
		// compare first character with every other, they all must be same
		if (missingCharacters.size() != 0)
		{
			if (missingCharacters.size() == 1)
			{
				// if missing charcters is only one then password is valid.
				valid = true;
				return valid;
			}
			char first = missingCharacters[0];
			for (int i = 1; i < missingCharacters.size(); i++)
			{
				if (first != missingCharacters[i])
				{
					valid = false;
					break;
				}
			}
		}		
	}
	return valid;
}

bool CheckValidity(string enteredPwd, string expectedPwd)
{
	int enteredPwdLength = enteredPwd.length();
	int expectedPwdLength = expectedPwd.length();
	int diff = expectedPwdLength - enteredPwdLength;
	// if difference is less than 0 then entered password is longer than expected; invalid
	if (diff < 0)
		return false;
	else if (diff == 0)
	{
		// since difference is same, check if password is same
		if (enteredPwd == expectedPwd)
		{
			return true;
		}
	}
	else
	{
		// there is difference in length of passwords, check the validity
		return Check(enteredPwd, expectedPwd, diff);
	}
}

int main()
{
	string enteredPwd;
	string expectedPwd;
	cout << "Entered password:";
	cin >> enteredPwd;
	cout << "\nExpected password:";
	cin >> expectedPwd;
	if (CheckValidity(enteredPwd, expectedPwd))
	{
		cout << "Valid" << endl;
	}
	else
	{
		cout << "Invalid" << endl;
	}
}