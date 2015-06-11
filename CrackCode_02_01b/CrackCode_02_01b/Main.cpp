/*
Write code to remove duplicates from an unsorted linked list
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include<iostream>
#include<unordered_set>

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

	void InsertNode(Node *node)
	{
		if (head == NULL)
		{
			head = new Node();
			head->data = node->data;
			head->next = NULL;
		}
		else
		{
			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			node->next = NULL;
			temp->next = node;
		}
	}

	bool IsEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}

	void Display()
	{
		if (!IsEmpty())
		{
			Node *temp = head;
			while (temp != NULL)
			{
				cout << temp->data << ",";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void RemoveDuplicates()
	{		
		Node *current = head;
		Node *previous = new Node();
		while (current->next != NULL)
		{
			// iterate all
			Node *runner = new Node();
			runner = head;
			// compare current with all earlier nodes
			while (runner != current)
			{
				if (runner->data == current->data)
				{
					previous->next = current->next;
					Node *redundantNode = current;
					if (current->next != NULL)
					{
						current = current->next;
					}					
					delete(redundantNode);
					break;
				}
				runner = runner->next;
			}
			if (runner == current)
			{
				previous = current;
			}			
			current = current->next;
		}
	}
};

int main()
{
	LinkedList *list = new LinkedList();
	Node *node = new Node();
	node->data = 1;
	list->InsertNode(node);

	node = new Node();
	node->data = 14;
	list->InsertNode(node);

	node = new Node();
	node->data = 9;
	list->InsertNode(node);

	node = new Node();
	node->data = 14;
	list->InsertNode(node);

	node = new Node();
	node->data = 14;
	list->InsertNode(node);

	node = new Node();
	node->data = 14;
	list->InsertNode(node);

	node = new Node();
	node->data = 21;
	list->InsertNode(node);

	node = new Node();
	node->data = 99;
	list->InsertNode(node);

	node = new Node();
	node->data = 21;
	list->InsertNode(node);

	list->Display();

	list->RemoveDuplicates();

	list->Display();
}