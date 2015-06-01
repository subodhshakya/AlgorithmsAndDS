#include<iostream>
#include<vector>

using namespace std;

int coins[50] = { 0 };
int split[50] = { 0 };

int MakeChangeDynamicProgramming(int c, vector<int> denominationList)
{
	for (int i = 1; i <= c; i++)
	{
		// This is base case
		if (i == 1 || i == 4 || i == 5)
		{
			coins[i] = 1;
			split[i] = 0;
		}
		else
		{
			int minCoins = INT_MAX;
			int bestSplit = 0;			
			
			vector<int> denom;
			denom.push_back(0);
			for (int k = 0; k < denominationList.size(); k++)
			{
				denom.push_back(denominationList[k]);
			}

			for (int c1 = 1; c1 <= 3; c1++)
			{
				if (denom[c1]<i)
				{
					if ((1 + coins[i - denom[c1]])<minCoins)
					{
						minCoins = 1 + coins[i - denom[c1]];
						bestSplit = denom[c1];
					}
				}
			}
			coins[i] = minCoins;
			split[i] = bestSplit;
		}
	}
	return coins[c];
}

int main()
{
	vector<int> denominationList = { 1, 4, 5 };
	int change;
	cout << "Enter amount in $ you want change for: ";
	cin >> change;
	int minCoins = MakeChangeDynamicProgramming(change, denominationList);
	cout << "Minimum number of coins: " << minCoins << endl;
}