/*
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time.

Approach 1: Storing min in each node of stack
*/

#include<iostream>
#include<climits>

using namespace std;

struct Node
{
	int data;
	int min;
	Node *next;
};

class Stack
{
	Node *top;
public:
	Stack()
	{
		top = NULL;
	}

	void push(int data)
	{
		if (top == NULL)
		{
			top = new Node();
			top->data = data;
			top->min = data;
			top->next = NULL;
		}
		else
		{
			Node *newNode = new Node();
			int currentMin = top->min;
			if (data < currentMin)
			{
				currentMin = data;
			}
			newNode->data = data;
			newNode->min = currentMin;
			newNode->next = top;
			top = newNode;
		}
	}

	int pop()
	{
		if (top == NULL)
		{
			throw "Stack is empty";
		}
		else
		{
			Node *currentNode = top;
			int topData = currentNode->data;
			top = top->next;
			delete(currentNode);
			return topData;
		}
	}

	int min()
	{
		if (top == NULL)
		{
			return INT_MAX;
		}
		else
		{
			return top->min;
		}
	}
};

int main()
{
	Stack stk;
	stk.push(15);
	stk.push(25);
	stk.push(88);
	stk.push(9);
	stk.push(3);

	cout << "Current min: " << stk.min()<<endl;
	cout << "Pop: " << stk.pop() << endl;
	cout << "Pop: " << stk.pop() << endl;
	cout << "Current min: " << stk.min() << endl;
}