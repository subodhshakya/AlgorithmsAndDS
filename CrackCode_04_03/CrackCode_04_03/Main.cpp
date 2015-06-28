/*
Given a sorted (increasing order) array with unique integer elements, write an algo. to create a 
binary search tree with minimal height.
*/

#include<iostream>

using namespace std;

const int MAX_SIZE = 10;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int n)
	{
		data = n;
	}
};

TreeNode *createMinimalBST(int arr[], int start, int end)
{
	if (end < start)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	TreeNode *n = new TreeNode(arr[mid]);
	n->left = createMinimalBST(arr, start, mid - 1);
	n->right = createMinimalBST(arr, mid + 1, end);
	return n;
}

TreeNode *createMinimalBST(int array[])
{
	return createMinimalBST(array, 0, MAX_SIZE - 1);
}

int main()
{
	int array[MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9};
	TreeNode *root = createMinimalBST(array);
}