/*********************************************************************************************************
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
Implement a data structure SetOfStacks that mimics this.
*********************************************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

const int MAXSTACKSIZE = 10;

struct Node
{
	int data;
	Node *next;
};

class Stack
{
	Node *top;
	int stackSize;
public:
	Stack()
	{
		top = NULL;
		stackSize = 0;
	}
	void push(int data)
	{
		if (top == NULL)
		{
			top = new Node();
			top->data = data;
			top->next = NULL;
			stackSize = 1;
		}
		else
		{
			Node *newNode = new Node();
			newNode->data = data;
			newNode->next = top;
			top = newNode;
			stackSize++;
		}
	}

	int pop()
	{
		if (top == NULL)
		{
			throw "Stack is empty!";
		}
		else
		{			
			Node *current = top;
			int retData = current->data;
			top = top->next;
			delete(current);
			stackSize--;
			return retData;
		}
	}

	int GetStackSize()
	{
		return stackSize;
	}
};

class SetOfStacks
{
	vector<Stack> StackList;
};

int main()
{

}