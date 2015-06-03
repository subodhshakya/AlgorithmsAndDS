#include<iostream>
#include<vector>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

float advisedMean(vector<int> data)
{
	int s = 0, m = 0, l = 0;
	int sum = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] > s)
		{
			s = data[i];
		}
		if (s>m)
		{
			swap(&s, &m);
		}
		if (m>l)
		{ 
			swap(&m, &l);
		}
		sum += data[i];
	}
	float average = (sum - (s + m + l)) / (data.size() - 3);
	return average;
}

int main()
{
	vector<int> data = {5,8,98,4,36,14,55,87}; 
	cout << advisedMean(data);
}