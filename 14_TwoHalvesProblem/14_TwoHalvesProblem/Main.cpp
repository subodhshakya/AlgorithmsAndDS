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