/*
Multiplicative iteration. Assume letters are A=1,B=2....The number N=4 then A=1*4=4.If result is greater than 26 mod 26.
Input a string and give a encrypted result as output.
*/

#include<iostream>
#include<string>

using namespace std;

string Encrypt(string inputString, int N)
{
	string output = "";
	for (int i = 0; i < inputString.length(); i++)
	{
		if (isupper(inputString[i]))
		{
			char outputChar = ((inputString[i] - 64) * 4) % 26;
			output += outputChar;
		}
		else
		{
			output += inputString[i];
		}
	}
	return output;
}

int main()
{
	string inputString;
	cout << "Enter a string to encrypt: ";
	getline(cin, inputString);
	cout << "\nEncrypted string: " << Encrypt(inputString, 4) << endl;
}