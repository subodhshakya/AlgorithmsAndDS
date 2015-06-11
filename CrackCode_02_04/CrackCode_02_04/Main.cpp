/*
You have two numbers represented by a linked list, where each node contains a single digit  The digits are stored in reverse order, such that the 1’s digit is at the head of
the list  Write a function that adds the two numbers and returns the sum as a linked
list
EXAMPLE
Input: (3 -> 1 -> 5), (6 -> 9 -> 2)
Output: 9 -> 0 -> 8
*/
#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
	Node *head;
public:
	LinkedList()
	{
		head = NULL;
	}
	void Insert(int data)
	{
		if (head == NULL)
		{
			head = new Node();
			head->data = data;
			head->next = NULL;
		}
		else
		{
			Node *current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			Node *newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;
			current->next = newNode;
		}
	}

	int GetNumberRepresentation()
	{
		int accumulator = 0;
		Node *current = head;
		int multiplier = 1;
		while (current != NULL)
		{
			int digit = current->data;
			accumulator = digit*multiplier + accumulator;
			multiplier *= 10;
			current = current->next;
		}
		return accumulator;
	}

	void Display()
	{
		if (head != NULL)
		{
			Node *current = head;
			while (current != NULL)
			{
				cout << current->data << "->";
				current = current->next;
			}
			cout << endl;
		}
	}
};

LinkedList Add(LinkedList l1, LinkedList l2)
{
	int a = l1.GetNumberRepresentation();
	int b = l2.GetNumberRepresentation();
	int sum = a + b;
	LinkedList l3;
	while (sum != 0)
	{
		int r = sum % 10;
		l3.Insert(r);
		sum = sum / 10;
	}
	return l3;
}

int main()
{
	LinkedList l1;	
	LinkedList l2;
	l1.Insert(3);
	l1.Insert(1);
	l1.Insert(5);
	l1.Display();

	l2.Insert(6);
	l2.Insert(9);
	l2.Insert(2);
	l2.Display();

	LinkedList l3 = Add(l1, l2);
	l3.Display();
}