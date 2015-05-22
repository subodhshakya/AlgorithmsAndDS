#include<iostream>
#include<vector>

using namespace std;

void printWellOrdered(int number, int prev, int n) {

	if (n == 0){
		cout << number<<endl;
		return;
	}

	for (int i = (prev + 1); i<(11 - n); i++){
		printWellOrdered(number * 10 + i, i, n - 1);
	}

}

int main()
{
	vector<int> arr;	
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(9);
	arr.push_back(1);
	printWellOrdered(0, 0, 4);
	cout << "Hello world" << endl;
}