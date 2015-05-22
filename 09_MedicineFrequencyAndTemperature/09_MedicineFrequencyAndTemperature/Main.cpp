/*
create a class to tell a nurse the frequency of medicine that a patient must take, i.e. a system to tell patients when 
to take medication and create a class with an object that holds temperatures of a person and can say whether or not they 
have a fever.
*/

#include<iostream>

using namespace std;

class MedicineFrequency
{
private:
	string medicineName;
	int frequencyPerDay;
	int timeIntervalInHours;
	bool beforeFood;
public:
	MedicineFrequency(string p_medName, int p_freqPerDay, int p_timeInterval, bool p_beforeFood)
	{
		medicineName = p_medName;
		frequencyPerDay = p_freqPerDay;
		timeIntervalInHours = p_timeInterval;
		beforeFood = p_beforeFood;
	}

	string TellFrequency()
	{		
		cout << "Frequency per day: " << frequencyPerDay << endl;
		cout<< "Time interval(hours): " << timeIntervalInHours<<endl;
	}
};

class PatientTemperature
{
private:
	string patientName;
	float temperature;

public:
	PatientTemperature(string name, float temp)
	{
		patientName = name;
		temperature = temp;
	}

	bool HasFever()
	{
		if (temperature > 37)
			return true;
		return false;
	}
};

int main()
{

}