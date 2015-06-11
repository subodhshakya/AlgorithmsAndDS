/*
Implement an algorithm to find the nth to last element of a singly linked list
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
		}
	}

	Node * FindNthFromLast(int n)
	{
		Node *p1 = new Node();
		Node *p2 = new Node();
		p1 = head;
		p2 = head;
		if (head == NULL || n < 1)
		{
			return NULL;
		}
		else
		{
			int count = 0;
			while (count != n - 1)
			{
				p2 = p2->next;
				count++;
			}
			while (p2->next != NULL)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
	}
};

int main()
{

}