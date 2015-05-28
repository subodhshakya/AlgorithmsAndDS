/*
RGBCompare
Given a string of RGB value (rr, gg, bb) which represents in hexadecimal. Compare if rr or gg or bb is the biggest, 
or two of those values are equal and larger than the third one, or three values are equal with each other.
*/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void PrintComparison(string inputStr)
{
	string truncInput = inputStr.substr(1, inputStr.length() - 2);
	string token;
	stringstream ss(truncInput);
	string RGB[3];
	int i = 0;
	while (getline(ss, token, ','))
	{
		RGB[i] = token;
		i++;
	}
	long a = strtol(RGB[0].c_str(),NULL,16);
	long b = strtol(RGB[1].c_str(), NULL, 16);
	long c = strtol(RGB[2].c_str(), NULL, 16);
	if (a == b && b == c)
	{
		cout << "RGB are equal" << endl;
	}
	else if ((a == b) && (a > c))
	{
		cout << "R and G are equal and larger than B" << endl;
	}
	else if ((a == c) && (a > b))
	{
		cout << "R and B are equal and larger than G" << endl;
	}
	else if ((b == c) && (b > a))
	{
		cout << "G and B are equal and larger than R" << endl;
	}
	else
	{
		long max = 0;
		if (a > max)
			max = a;
		if (b > max)
			max = b;
		if (c > max)
			max = c;
		if (max == a)
			cout << "R is largest" << endl;
		else if (max == b)
			cout << "G is largest" << endl;
		else
			cout << "B is largest" << endl;
	}
}

int main()
{
	string hexRGB;
	cout << "Enter RGB in hex in format (rr,gg,bb): ";
	cin >> hexRGB;
	PrintComparison(hexRGB);
}