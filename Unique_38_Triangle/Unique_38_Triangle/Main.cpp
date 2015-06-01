/*
Given a array
{{ 4,7,3,6,7}}

construct a triangle like
{{81}}
{{40,41}}
{{21,19,22}}
{{11,10,9,13}}
{{ 4,7,3,6,7}}
*/

#include<iostream>
#include<vector>

using namespace std;

void PrintTriangle(vector<int> dataAry)
{
	if (dataAry.size() == 0)
	{
		return;
	}

	int previous = dataAry[0];
	vector<int> outputAry;
	for (int i = 1; i < dataAry.size(); i++)
	{
		int sum = previous + dataAry[i];
		outputAry.push_back(sum);
		previous = dataAry[i];
	}
	PrintTriangle(outputAry);

	cout << "{{";
	for (int i = 0; i < dataAry.size(); i++)
	{
		if (i == dataAry.size() - 1)
		{
			cout << dataAry[i];
		}
		else
		{
			cout << dataAry[i] << ",";
		}		
	}
	cout << "}}";
	cout << endl;
}

int main()
{
	vector<int> dataAry = { 4, 7, 3, 6, 7 };
	PrintTriangle(dataAry);
}