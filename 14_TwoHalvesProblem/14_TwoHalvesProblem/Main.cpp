/*
2 numbers given . First no have to be divided into 2 halves such that the sum of its halves must be less than or equal 
to the second number. You have to find such 2 hal pairs which are as close to the second no.
*/
#include<iostream>

using namespace std;

void GenerateNumberPairs(int a, int b)
{
	for (int i = 1; i <= (a/2); i++)
	{
		int n1 = i;
		int n2 = a - i;
		if ((n1 + n2) <= b)
			cout << "(" << n1 << "," << n2 << ")";
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