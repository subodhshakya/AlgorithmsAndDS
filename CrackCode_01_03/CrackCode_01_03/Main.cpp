/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer  NOTE: One or two additional variables are fine
An extra copy of the array is not
FOLLOW UP
Write the test cases for this method
*/
#include<iostream>
#include<string>

using namespace std;

string removeDuplicates(string str) {
	if (str == "") return "";
	int len = str.length();
	if (len < 2) return "";	
	int tail = 1;	
	for (int i = 1; i < len; ++i) {
		int j;
		for (j = 0; j < tail; ++j) {
			if (str[i] == str[j]) break;			
		}
		if (j == tail) {
			str[tail] = str[i];
			++tail;				
		}			
	}
	 str[tail] = '\0';	
	 return str;
}

int main()
{
	string word;
	cout << "Enter a word: ";
	cin >> word;
	string noDuplicate = removeDuplicates(word);
	cout << "\n" << noDuplicate << endl;
}