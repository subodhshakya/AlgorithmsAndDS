/*
2.write a program to diaplay the advisered average for the list of numbers my omitting the largest number in the series.
eg :3,6,12,55,289,600,534,900 and 172.
avg=(3+6+12+55+289+172) /6and eliminating 534,900,600

*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

float AdvisedAverage(vector<int> data, int numCountToIgnore)
{
	sort(data.begin(), data.end());
	int sum = 0;
	for (int i = 0; i < data.size() - numCountToIgnore; i++)
	{
		sum += data[i];
	}
	float average = (float)sum / (data.size() - numCountToIgnore);
	return average;
}

int main()
{
	vector<int> data = { 3, 6, 12, 55, 289, 600, 534, 900, 172 };
	float avg = AdvisedAverage(data, 3);
	cout << "Advised Average: " << avg << endl;
}