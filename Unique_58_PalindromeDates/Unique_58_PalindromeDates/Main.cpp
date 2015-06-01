/*
Write a program to generate all palindrome dates by taking the beginning and the ending dates as an input from the user. 
The format of the date is given as MMDDYYYY.
*/

#include<iostream>
#include<string>

using namespace std;

bool IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}

bool IsValidDate(string MMDDYYYY)
{
	int month = stoi(MMDDYYYY.substr(0, 2));
	int day = stoi(MMDDYYYY.substr(2, 2));
	int year = stoi(MMDDYYYY.substr(4, 4));
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31)
		{
			return false;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
		{
			return false;
		}
		break;
	case 2:
		if (IsLeapYear(year))
		{
			if (day > 29)
			{
				return false;
			}			
		}
		else
		{
			if (day > 28)
			{
				return false;
			}
		}
		break;
	default:
		return false;
		break;
	}
	return true;
}

bool IsPalindromeDate(string MMDD, string YYYY)
{
	string revYear = "";
	for (int i = YYYY.length() - 1; i >= 0; i--)
	{
		revYear += YYYY[i];
	}
	if (MMDD == revYear)
	{
		return true;
	}
}

void GeneratePalindromeDate(string startDate, string endDate)
{
	int startYear = stoi(startDate.substr(4, 4));
	int endYear = stoi(endDate.substr(4, 4));

	for (int i = startYear; i <= endYear; i++)
	{
		string year = to_string(i);
		string revYear = "";
		for (int j = year.length() - 1; j >= 0; j--)
		{
			revYear += year[j];
		}
		string MMDD = revYear;
		if (IsValidDate(MMDD+year))
		{
			if (IsPalindromeDate(MMDD, year))
			{
				cout << MMDD + year << endl;
			}
		}
	}
}

int main()
{
	GeneratePalindromeDate("01011000","12129999");
}