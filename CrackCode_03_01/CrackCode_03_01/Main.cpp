/*
Describe how you could use a single array to implement three stacks.

Approach 1: Fixed Division
*/

#include<iostream>

using namespace std;

const int stackSize = 10;

class Stack
{
	int buffer[stackSize * 3];
	int stackPointer[3];
public:
	Stack()
	{
		stackPointer[0] = -1;
		stackPointer[1] = -1;
		stackPointer[2] = -1;
	}

	int GetBufferIndex(int stackNumber)
	{
		return stackSize * stackNumber + stackPointer[stackNumber] + 1;
	}

	bool Push(int data, int stackNumber)
	{
		int currentStackIndex = stackPointer[stackNumber];
		if (currentStackIndex > stackSize)
		{
			return false;
		}
		int bufferIndex = GetBufferIndex(stackNumber);
		buffer[bufferIndex] = data;
		stackPointer[stackNumber]++;
	}
	
	int Pop(int stackNumber)
	{
		if (stackPointer[stackNumber] < 0)
		{
			throw "Stack is empty";
		}

		int retData = buffer[stackNumber * stackSize + stackPointer[stackNumber]];
		stackPointer[stackNumber]--;
		return retData;
	}

	int Peek(int stackNumber)
	{
		int currentIndex = stackPointer[stackNumber];
		if (currentIndex < 0)
		{
			throw "Stack is empty";
		}

		return buffer[stackNumber * stackSize + stackPointer[stackNumber]];
	}
	
};

int main()
{
	Stack stk;
	stk.Push(24, 0);
	stk.Push(4, 0);
	stk.Push(56, 0);
	stk.Push(77, 0);
	stk.Push(67, 1);
	stk.Push(88, 1);
	stk.Push(90, 2);
	stk.Push(46, 2);
	stk.Push(84, 2);

	cout << "Poping stack 1:" << stk.Pop(0)<<endl;
	cout << "Poping stack 1:" << stk.Pop(0)<<endl;
	cout << "Poping stack 2:" << stk.Pop(1) << endl;
	cout << "Poping stack 2:" << stk.Pop(1) << endl;
	cout << "Poping stack 3:" << stk.Pop(2) << endl;
	cout << "Poping stack 3:" << stk.Pop(2) << endl;
}