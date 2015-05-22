/*
glitch is a walking robort moves in a peculiar problem: it takes x steps forward , then x+1 steps backward, 
then 2x steps forward, x+2 steps backward,3x steps forward x+3 steps backward , and so on... until it has taken y steps,
glitch turns 180 degrees before continuning with its pattern . write a program that prompts x and y and total number of 
steps taken and outputs how many steps away from its starting point
*/
#include<iostream>

using namespace std;

int main()
{
	int x; int y; int totalSteps;
	cout << "Enter Starting point (x steps): ";
	cin >> x;
	cout << "Enter Turning point (y steps): ";
	cin >> y;
	cout << "Enter Total number of steps taken: ";
	cin >> totalSteps;	
	int xsteps = x;
	int totalCurrentSteps = 0;
	int offset = 1;
	while (totalCurrentSteps <= totalSteps)
	{
		int step1 = x*offset;
		int step2 = x + offset;
		// this is deflection point
		if (totalCurrentSteps >= y)
		{			
			xsteps += (step2 - step1);			
		}
		else
		{ 						
			xsteps += (step1 - step2);			
		}	
		offset++;
		totalCurrentSteps += step1 + step2;
	}	
	cout << "Steps from starting point: " << xsteps << endl;
}