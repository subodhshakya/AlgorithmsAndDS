/*
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element?
Push, pop and min should all operate in O(1) time.

Approach 2: Using separate min stack
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct MinNode :Node
{
	int count;
	MinNode *next;
};

class Stack
{
	Node *top;
	MinNode *minTop;
public:
	Stack()
	{
		top = NULL;
		minTop = NULL;
	}
	void Push(int data)
	{
		if (top == NULL)
		{
			top = new Node();
			top->data = data;
			top->next = NULL;
			minTop = new MinNode();
			minTop->data = data;
			minTop->next = NULL;
			minTop->count = 1;
		}
		else
		{
			Node *currentNode = new Node();
			currentNode->data = data;
			currentNode->next = top;
			top = currentNode;

			if (data < minTop->data)
			{
				MinNode *currentMinNode = new MinNode();
				currentMinNode->data = data;
				currentMinNode->next = minTop;
				currentMinNode->count = 1;

				//minTop->next = currentMinNode;
				minTop = currentMinNode;
			}
			else if (data == minTop->data)
			{ 
				int currentCount = minTop->count;
				currentCount++;
				minTop->count = currentCount;
			}
		}
	}

	int Pop()
	{
		if (top == NULL)
		{
			throw "Stack is empty!";
		}
		else
		{
			Node *current = top;
			int topData = current->data;
			top = top->next;

			MinNode *currentTop = minTop;
			if (topData == currentTop->data)
			{
				if (currentTop->count > 1)
				{
					currentTop->count--;
				}
				else
				{
					minTop = minTop->next;
					delete(currentTop);
				}
			}
			delete(current);
			return topData;
		}
	}

	int Min()
	{
		if (minTop == NULL)
		{
			throw "Min Stack is Empty";
		}
		else
		{
			return minTop->data;
		}
	}

	int Peek()
	{
		if (top == NULL)
		{
			throw "Stack is Empty!";
		}
		else
		{
			return top->data;
		}
	}
};

int main()
{
	Stack stk;
	stk.Push(25);
	stk.Push(3);
	stk.Push(2);
	stk.Push(1);
	stk.Push(27);
	stk.Push(47);

	cout << "Min: " << stk.Min()<<endl;
	cout << "Pop: " << stk.Pop()<<endl; // 47
	cout << "Min: " << stk.Min() << endl;
	cout << "Pop: " << stk.Pop() << endl; // 27
	cout << "Min: " << stk.Min() << endl;
	cout << "Pop: " << stk.Pop() << endl; // 1
	cout << "Min: " << stk.Min() << endl;
	cout << "Pop: " << stk.Pop() << endl; // 2
	cout << "Min: " << stk.Min() << endl;
	cout << "Pop: " << stk.Pop() << endl; // 3
	cout << "Min: " << stk.Min() << endl;
	cout << "Pop: " << stk.Pop() << endl; //25
	cout << "Min: " << stk.Min() << endl;
}