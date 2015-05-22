/*
design a class to provide information about the disease of a patient with details like who reported the 
disease(patient/doctor/relative), different symptoms of the disease, severity, method that returns when was that 
disease detected in that patient. Along with info if it is allergy and not a disease so that it can be updated easily 
along with record the time of the allergy report
*/

#include<iostream>
#include<vector>

using namespace std;

class DateTime
{
public:
	int mm;
	int dd;
	int yyyy;
};


class Disease
{
private:
	string reporter;
	vector<string> symptoms;
	int severityLevel;
	DateTime detectionDate;

	Disease(string p_reporter, vector<string> p_symptoms, int p_severityLevel, DateTime p_detectionDate)
	{
		reporter = p_reporter;
		symptoms = p_symptoms;
		severityLevel = p_severityLevel;
		detectionDate = p_detectionDate;
	}

	DateTime GetDetectionDate()
	{
		return detectionDate;
	}
};

int main()
{

}