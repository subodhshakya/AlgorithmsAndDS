/*
well ordered string
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printWellOrdered(string word, int prev, int n) 
{

	if (n == 0){
		cout << word << endl;		
		return;
	}

	for (int i = (prev + 1); i<=(27 - n); i++){
		printWellOrdered(word + (char)(i + 96), i, n - 1);
		printWellOrdered(word + (char)(i + 64), i, n - 1);
	}

}

int main()
{	
	int length;
	cout << "Enter length of well ordered string: ";
	cin >> length;
	printWellOrdered("", 0, length);	
}