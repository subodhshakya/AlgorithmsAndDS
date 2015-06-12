/*
Implement a function to check if a linked list is a palindrome

Approach 1
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

bool IsPalindrome(Node *head)
{
	Node *current = head;
	Node *revEnd = new Node();
	Node *revCurrent = new Node();
	int count = 0;
	while (current != NULL)
	{
		if (revEnd == NULL)
		{
			revEnd = new Node();
			revEnd->data = current->data;
			revEnd->next = NULL;
			revCurrent = revEnd;
		}
		else
		{
			Node *newNode = new Node();
			newNode->data = current->data;
			newNode->next = revCurrent;
			revCurrent = newNode;
		}
		current = current->next;
		count++;
	}
	int newCount = 0;
	bool isPal = true;
	Node *list1Current = head;
	Node *list2Current = revCurrent;
	while (newCount <= (count / 2))
	{
		if (list1Current->data != list2Current->data)
		{
			isPal = false;
			break;
		}
		list1Current = list1Current->next;
		list2Current = list2Current->next;
		newCount++;
	}
	return isPal;
}

class LinkedList
{
	Node *head;
public:
	LinkedList()
	{
		head = NULL;
	}

	Node *GetHead()
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
	ll->Insert(15);
	ll->Insert(12);
	ll->Insert(13);
	ll->Insert(55);
	ll->Insert(55);
	ll->Insert(13);
	ll->Insert(12);
	ll->Insert(15);

	if (IsPalindrome(ll->GetHead()))
	{
		cout << "is palindrome!" << endl;
	}
	else
	{
		cout << "Not palindrome!" << endl;
	}
}