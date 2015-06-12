/*
Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater 
than or equal to x
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node * Partition(Node *head, int x)
{
	Node *beforeStart = new Node();
	Node *beforeEnd = new Node();	

	Node *afterStart = new Node();
	Node *afterEnd = new Node();

	beforeStart = beforeEnd = afterStart = afterEnd = NULL;
	// This is easier problem
	// start iterating the list from head to NULL
	// if node is less than given node.data then add it to beforeEnd
	// else add it to afterEnd;
	// Finally merge by: beforeEnd->next = afterStart;
	// return beforeStart;

	Node *current;
	current = new Node();
	current = head;
	while (current != NULL)
	{
		if (current->data < x)
		{
			if (beforeStart == NULL)
			{
				beforeStart = beforeEnd = current;
			}
			else
			{
				beforeEnd->next = current;
				beforeEnd = current;
			}
		}
		else
		{
			if (afterStart == NULL)
			{
				afterStart = afterEnd = current;
			}
			else
			{
				afterEnd->next = current;
				afterEnd = current;
			}
		}
		current = current->next;
	}
	if (beforeEnd != NULL && afterStart != NULL)
	{
		beforeEnd->next = afterStart;
	}

	return beforeStart;
}

void Display(Node *head)
{
	Node *current = head;
	while (current != NULL)
	{
		cout << current->data << ",";
		current = current->next;
	}
}

class LinkedList
{
	Node *head;
public:
	Node * GetHead()
	{
		return head;
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
};

int main()
{
	LinkedList *ll = new LinkedList();
	ll->Insert(25);
	ll->Insert(7);
	ll->Insert(24);
	ll->Insert(9);
	ll->Insert(99);
	ll->Insert(104);
	ll->Insert(16);
	ll->Insert(88);

	Node *head = Partition(ll->GetHead(), 30);
	Display(head);
}