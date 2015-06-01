/*
There are two roommates. Each one prepares a list for grocery store. Make a combined list without any duplicates.
*/
#include<iostream>
#include<unordered_set>
using namespace std;

vector<string> GetCombinedList(vector<string> listA, vector<string> listB)
{
	unordered_set<string> combinedSearchList; // to search in linear time
	vector<string> combinedList;
	for (int i = 0; i < listA.size(); i++)
	{
		auto got = combinedSearchList.find(listA[i]);
		if (got == combinedSearchList.end())
		{
			combinedSearchList.insert(listA[i]);
			combinedList.push_back(listA[i]);
		}
	}
	for (int j = 0; j < listB.size(); j++)
	{
		auto got = combinedSearchList.find(listB[j]);
		if (got == combinedSearchList.end())
		{
			combinedSearchList.insert(listB[j]);
			combinedList.push_back(listB[j]);
		}
	}
	return combinedList;
}

int main()
{
	vector<string> listA = { "apple", "orange", "tea", "coffee" };
	vector<string> listB = { "lime", "bread", "tea", "coffee" };
	vector<string> combinedList = GetCombinedList(listA, listB);
}