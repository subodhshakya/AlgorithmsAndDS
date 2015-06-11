/*
Implement an algorithm to delete a node in the middle of a single linked list, given
only access to that node
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

/*
Solution is really simple:
*/
//given n:

void Delete(Node *n)
{
	Node *next = n->next;
	n->data = next->data;
	n->next = next->next;
	delete(next);
}

int main()
{

}