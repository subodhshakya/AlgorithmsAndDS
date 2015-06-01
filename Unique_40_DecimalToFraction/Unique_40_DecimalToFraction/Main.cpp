/*
Let the user enter a decimal number. The range allowed is 0.0001 to 0.9999. Only four decimal places are allowed. 
The output should be an irreducible fraction.
Eg: If the user enters 0.35, the irreducible fraction will be 7/20.
*/

#include<iostream>

using namespace std;

int HCF(int a, int b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;

	if (a < b)
		return HCF(a, b % a);
	else
		return HCF(b, a % b);
}

void PrintFraction(float number)
{
	int denominator = 10000;
	int numerator = number * denominator;
	int hcf = HCF(numerator, denominator);
	int reducedNumerator = numerator / hcf;
	int reducedDenominator = denominator / hcf;
	cout << reducedNumerator << "/" << reducedDenominator<<endl;
}

int main()
{
	float number;
	cout << "Enter decimal with in range of (0.0001 to 0.9999): ";
	cin >> number;
	PrintFraction(number);
}