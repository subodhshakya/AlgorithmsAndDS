#include<iostream>
#include<vector>

using namespace std;

bool IsJumpSuccess(vector<int> arr)
{
	int i = 0;	
	while (i < arr.size())
	{
		int jumpStep = arr[i];
		if (jumpStep == 0 || i == arr.size()-1)
			break;
		i += jumpStep;
	}
	if (i == (arr.size() - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	vector<int> A;
	//A = { 2, 3, 1, 1, 4 };
	A = { 3, 2, 1, 0, 4 };
	if (IsJumpSuccess(A))
	{
		cout << "Jump to end success!" << endl;
	}
	else
	{
		cout << "Jump to end not possible!" << endl;
	}
}