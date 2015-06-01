/*
User inputs a sequence of digits. Every digit is a keystroke, that is equivalent to some character out of a sequence of characters. Digit zero and five mean NULL. The table is given below
0 - NULL
1 - v, t, f, r, q
2 - f, t, k
3 - w, z, b, g
4 - r, s
5 - NULL
6 - f, i, r
7 - p
8 - l, o
9 - p

Generate all possible character sequence for a given sequence of digits.
Ex - If the user input 9801, your program should generate
{plv, plt, plf, plr, plq, pov, pot, pof, por, poq} (not necessarily in this order).

This problem is somewhat similar to the SMS problem. It basically boils down to generating a cartesian product of the character sets corresponding to keys.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> pattern = { "", "vtfrq", "ftk", "wzbg", "rs", "", "fir", "p", "lo", "p" };

void Generate(string keystroke, int curr, int size)
{
	static string str;

	if (curr==size)
	{
		cout << str << endl;
		return;
	}

	int digit = keystroke[curr] - '0';

	if (pattern[digit].empty())
	{
		Generate(keystroke, curr + 1, size);
		return;
	}

	for (int i = 0; i < pattern[digit].length(); i++)
	{
		str.push_back(pattern[digit][i]);
		Generate(keystroke, curr + 1, size);
		str.erase(str.end() - 1); // pop since you are backtracking
	}
}

int main()
{
	string keystroke;	

	cout << "Enter your keystroke: ";
	cin >> keystroke;

	Generate(keystroke, 0, keystroke.length());
}