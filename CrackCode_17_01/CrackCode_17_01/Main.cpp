/*
write a function to swap a number in place (that is, without temporary variables)
*/
#include<iostream>

using namespace std;

void Swap(int &a, int &b)
{
	a = a - b; // a = 25; b = 33 --> a = 25 - 33 = -8;
	b = a + b; // b = -8 + 33 --> b = 25 (Converted to a) ; adding difference to b converts it to a
	a = b - a; // a = 25 - (-8) = 33 (Converted to b)
}

void Swap_opt(int &a, int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "a: " << a << ", b: " << b << endl;
	Swap(a, b);
	cout << "a: " << a << ", b: " << b << endl;

	Swap_opt(a, b);
	cout << "a: " << a << ", b: " << b << endl;
	return 0;
}