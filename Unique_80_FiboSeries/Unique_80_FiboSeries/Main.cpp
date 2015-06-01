#include<iostream>

using namespace std;

int Fibo(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	cout << Fibo(0) << ",";
	cout << Fibo(1)<<",";
	cout << Fibo(2)<<",";
	cout << Fibo(3)<<endl;
}