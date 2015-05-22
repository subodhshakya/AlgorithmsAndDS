/*
Design a Binary search tree using Epic as Input
*/
#include<iostream>
#include<algorithm>

using namespace std;

class node
{
public:
	char data;
	node *left;
	node *right;
};

class BinarySearchTree
{
private:
	node *root;
public:

	node* sortedArrayToBST(char arr[], int start, int end) {
		if (start > end) return NULL;
		// same as (start+end)/2, avoids overflow.		
		int mid = start + (end - start) / 2;
		node *tnode = new node();
		tnode->data = arr[mid];
		tnode->left = sortedArrayToBST(arr, start, mid - 1);
		tnode->right = sortedArrayToBST(arr, mid + 1, end);		
		return tnode;
	}

	node* sortedArrayToBST(char arr[], int length) {
		return sortedArrayToBST(arr, 0, length - 1);
	}
};



int main()
{
	int size = 10;
	char arr[10] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c' ,'b','a'};
	std::sort(arr, arr + sizeof(arr));
	// get middle element's index in sorted array for root element in BST
	int rootindex = (0 + size) / 2;
	BinarySearchTree bst;	
	node *root =bst.sortedArrayToBST(arr,size);
}