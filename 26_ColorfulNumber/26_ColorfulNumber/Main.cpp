/*
colorful number
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> combList;

bool IsColorful()
{
	vector<int> productList;
	for (int i = 0; i < combList.size(); i++)
	{ 
		int accumulator = 1;
		for (int j = 0; j < combList[i].length(); j++)
		{
			int digit = combList[i][j] - '0';
			accumulator *= digit;
		}
		if (find(productList.begin(), productList.end(),accumulator) != productList.end())
		{
			return false;
		}
		else
		{
			productList.push_back(accumulator);
		}
	}
	return true;
}

void powerSet(string combNumber, int prev, string number,int totalLength,int n)
{

	if (n == 0){
		combList.push_back(combNumber);
		cout << combNumber << endl;
		return;
	}

	for (int i = (prev + 1); i <= (totalLength+1 - n); i++){
		powerSet(combNumber + number[i - 1], i, number, totalLength, n - 1);
	}
}

int main()
{
	string number;
	cout << "Enter a number: ";
	cin >> number;	
	
	for (int i = 0; i < number.length(); i++)
	{
		powerSet("", 0, number, number.length(), i+1);
	}
	if (IsColorful())
	{
		cout << "\nColorful number!\n" << endl;
	}
	else
	{
		cout << "\nNot Colorful number!\n" << endl;
	}
}