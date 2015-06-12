/*
Implement a function to check if a linked list is a palindrome

Approach 2
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

bool IsPalindrome(Node *head)
{
	vector<int> stack;
	Node *slow = head;
	Node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		stack.push_back(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	bool isPal = true;
	while (slow != NULL)
	{
		int top = stack.back();
		if (top != slow->data)
		{
			isPal = false;
			break;
		}
		stack.pop_back();
		slow = slow->next;
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