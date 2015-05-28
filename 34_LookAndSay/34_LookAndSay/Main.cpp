/*
Write a program to print the below series:
1 11 21 1211 111221 312211 13112221 ....
Another example of the series:
12 1112 3112 132112 1113122112 ....

You will be given a number. You will have to print the first ten numbers in the series. The series is basically the number of occurrence followed by the number. The occurrence should be continuous.
Alternative explanation

Implement LookAndSay function. For example, first, let user input a number, say 1. Then, the function will generate the next 10 numbers which satisfy this condition:
1, 11,21,1211,111221,312211...
explanation: first number 1, second number is one 1, so 11. Third number is two 1(previous number), so 21. next number one 2 one 1, so 1211 and so on...
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void LookAndSay(string number, int currentIteration, int numberOfItems)
{	
	if (currentIteration == numberOfItems)
	{
		return;
	}

	cout << number<<" ";

	char previous = number[0];
	int count = 1;
	string newString = "";
	if (number.length() == 1)
	{
		newString += to_string(count) + number[0];
	}	
	else
	{
		for (int i = 1; i <= number.length(); i++)
		{
			if (i == number.length())
			{
				newString += to_string(count) + number[i-1];
			}
			else
			{
				if (number[i] == previous)
				{
					count++;
				}
				else
				{
					newString += to_string(count) + previous;
					count = 1;//reset counter;
				}
			}
					
			previous = number[i];
		}
	}
	
	LookAndSay(newString, currentIteration + 1, numberOfItems);
}

int main()
{
	string number;
	int numberOfSteps;
	cout << "enter a number: ";
	cin >> number;
	cout << "enter number of items in sequence: ";
	cin >> numberOfSteps;
	LookAndSay(number, 0, numberOfSteps);
}