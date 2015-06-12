/*
2.6 Given a circular linked list, implement an algorithm which returns the node at the beginning of the loop.

Note:
This is a modification of a classic interview problem: detect if a linked list has a loop.
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node * GetStartingPoint(Node *head)
{
	Node *slow = new Node();
	Node *fast = new Node();
	slow = fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			// collison
			break;
		}
	}

	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return fast;
}

int main()
{
	Node *n1 = new Node();
	n1->data = 21;

	Node *n2 = new Node();
	n2->data = 51;
	n1->next = n2;

	Node *n3 = new Node();
	n3->data = 18;
	n2->next = n3;

	Node *n4 = new Node();
	n4->data = 85;
	n3->next = n4;

	Node *n5 = new Node();
	n5->data = 856;
	n4->next = n5;

	Node *n6 = new Node();
	n6->data = 221;
	n5->next = n6;

	Node *n7 = new Node();
	n7->data = 617;
	n6->next = n7;

	Node *n8 = new Node();
	n8->data = 954;
	n7->next = n8;

	n8->next = n3;

	Node *meetingNode = GetStartingPoint(n1);
	cout << meetingNode->data << endl;
}