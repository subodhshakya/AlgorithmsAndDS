/*
We are given a specific time(like 02:23), we need to get the angle between hour and minute(less than 180)
*/
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

float GetAngle(string timeStr)
{
	stringstream ss(timeStr);
	string token;
	float hour, minute;
	getline(ss, token, ':');
	hour = stof(token.c_str(), NULL);
	getline(ss, token, ':');
	minute = stof(token.c_str(), NULL);
	float hourFromMinuteHandDisplacement = ((float)minute / (float)60.0);
	float angle1 = ((hour + hourFromMinuteHandDisplacement) / 12.0) * 360.0;
	float angle2 = (minute / 60.0) * 360.0;
	float diff = abs(angle1 - angle2);
	if (diff>180)
	{
		return 360 - diff;
	}
	else
		return diff;
}

int main()
{
	string timeStr = "02:23";
	cout << GetAngle(timeStr) << endl;
}