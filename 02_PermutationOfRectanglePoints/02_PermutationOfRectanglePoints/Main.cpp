#include<iostream>

using namespace std;

void PrintCombination(int x, int y, int area);
void PrintAllPoints(int x, int y, int l, int b);

int main()
{
	int x, y;	
	int area = 0;
	cout << "Enter x coordinate: ";
	cin >> x;
	cout << "\nEnter y coordinate: ";
	cin >> y;
	cout << "\nEnter area: ";
	cin >> area;
	PrintCombination(x, y, area);
}

void PrintCombination(int x, int y, int area)
{
	for (int l = 1; l <= area; l++)
	{
		for (int b = 1; b <= area; b++)
		{
			if (area == (l*b))
			{
				PrintAllPoints(x, y, l, b);
			}
		}
	}
}

void PrintAllPoints(int x, int y, int l, int b)
{
	int px1 = x; int py1 = y;
	int px2 = x + l; int py2 = y;
	int px3 = x + l; int py3 = y + b;
	int px4 = x; int py4 = y + b;
	cout << "(" << px2 << "," << py2 << ")" << "," << "(" << px3 << "," << py3 << ")" << "," << "(" << px4 << "," << py4 << ")" << endl;
	//reflected vertically
	px2 = x - l; py2 = y;
	px3 = x - l; py3 = y + b;
	cout << "(" << px2 << "," << py2 << ")" << "," << "(" << px3 << "," << py3 << ")" << "," << "(" << px4 << "," << py4 << ")" << endl;
	
	//reflected horizontally
	px2 = x + l; py2 = y;
	px3 = x + l; py3 = y - b;
	px4 = x; py4 = y - b;
	cout << "(" << px2 << "," << py2 << ")" << "," << "(" << px3 << "," << py3 << ")" << "," << "(" << px4 << "," << py4 << ")" << endl;

	//reflected in x = -y
	px2 = x - l; py2 = y;
	px3 = x - l; py3 = y - b;
	px4 = x; py4 = y - b;
	cout << "(" << px2 << "," << py2 << ")" << "," << "(" << px3 << "," << py3 << ")" << "," << "(" << px4 << "," << py4 << ")" << endl;
}