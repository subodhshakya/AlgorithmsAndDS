/*
Week day calculation;
*/
#include<iostream>
#include<string>

using namespace std;

class Date
{
public:
	int mm;
	int dd;
	int yyyy;
	int day;
};

string FindDay(Date startDate,Date endDate)
{
	int years = endDate.yyyy - startDate.yyyy;
	int days = years * 365;
	int count = 2012;
	int leapYears = 52 / 4;
	days += leapYears + 31 + 28 + 6;
	int day = days % 7;
	int totalWeekDays = startDate.day + day;
	if (totalWeekDays > 7)
	{
		totalWeekDays -= 7;
	}
	switch (totalWeekDays)
	{
	case 1:
		return "Sunday";
		break;
	case 2: 
		return "Monday";
		break;
	case 3:
		return "Tuesday";
		break;
	case 4:
		return "Wednesday";
		break;
	case 5:
		return "Thursday";
		break;
	case 6:
		return "Friday";
		break;
	case 7:
		return "Saturday";
		break;
	default:
		return "";
		break;
	}
}

int main()
{
	Date startDate;
	startDate.mm = 1;
	startDate.dd = 1;
	startDate.yyyy = 2011;
	startDate.day = 7; // on actual calendar the day is Saturday;

	Date endDate;
	endDate.mm = 3;
	endDate.dd = 6;
	endDate.yyyy = 2064;
	endDate.day = 0;

	cout << FindDay(startDate, endDate) << endl;
}