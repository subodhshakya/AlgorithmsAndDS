/*
Given a number such as 123 having digits 1,2 and 3.
Now Product of Number and its digits is = 123*1*2*3 = 738. Now 123 is the seed number for 738. 
You would be given a number and you have to identify whether any seed element exists for that number. 
for Ex: - 4977 has two such seed numbers 79 and 711. You have to print both.
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a;
	cout << "enter a number: ";
	cin >> a;	
	for (int i = 1; i <= a; i++)
	{
		string numStr = to_string(i);
		int accumulator = i;
		for (int j = 0; j < numStr.length(); j++)
		{
			int digit = numStr[j] - '0';
			accumulator *= digit;
		}
		if (accumulator == a)
		{
			cout << i << endl;
		}
	}
}