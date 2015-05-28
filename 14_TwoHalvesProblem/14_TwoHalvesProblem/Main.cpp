/*
2 numbers given . First no have to be divided into 2 halves such that the sum of its halves must be less than or equal 
to the second number. You have to find such 2 hal pairs which are as close to the second no.
*/
#include<iostream>
#include<string>

using namespace std;

void GenerateNumberPairs(int a, int b)
{
	string firstNumber = to_string(a);
	int fLen = firstNumber.length();
	for (int i = 0; i < fLen - 1; i++)
	{
		string p1 = firstNumber.substr(0, i + 1);
		string p2 = firstNumber.substr(i + 1, fLen - i);
		int n1 = atoi(p1.c_str());
		int n2 = atoi(p2.c_str());
		if ((n1 + n2) <= b)
			cout << "(" << n1 << "," << n2 << ")" << endl;
	}	
	cout << endl;
}

int main()
{
	int a, b;
	cout << "Enter first number: ";
	cin >> a;
	cout << "\nEnter second number: ";
	cin >> b;
	GenerateNumberPairs(a, b);
}