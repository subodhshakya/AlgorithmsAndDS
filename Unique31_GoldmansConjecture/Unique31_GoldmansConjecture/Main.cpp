/*
Unique 31>
Goldbach's conjecture : Every even integer greater than 2 can be expressed as the sum of two primes.
Write a function which takes a number as input, verify if is an even number greater than 2 and 
also print at least one pair of prime numbers.
*/
#include<iostream>
#include<vector>

using namespace std;

bool IsPrime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number%i == 0)
		{
			return false;
		}
	}
	return true;
}

void PrintPrimePairs(int number)
{
	if (number > 2 && number % 2 != 0)
	{
		cout << "N/A" << endl;
	}
	else
	{
		vector<int> primeNumbers;
		for (int i = 3; i < number; i += 2)
		{
			if (IsPrime(i))
			{
				primeNumbers.push_back(i);
			}
		}
		int left = 0;
		int right = primeNumbers.size()-1;
		while (left < right)
		{			
			if (primeNumbers[left] + primeNumbers[right] < number)
			{
				left++;
			}
			else if (primeNumbers[left] + primeNumbers[right] > number)
			{
				right--;
			}
			else
			{
				cout << "(" << primeNumbers[left] << "," << primeNumbers[right] << ")" << endl;
				left++;
				right--;
			}
		}
	}
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	PrintPrimePairs(number);
}