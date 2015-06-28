/*
Implement a function to check if a binary tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that the heights of the two subtrees of any node
never differ by more than one.
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

class Tree
{
	TreeNode *root;
public:
	Tree()
	{
		root = NULL;
	}
	
	void BuildTree()
	{
		/*				50
				25				66
			11		33		45		88
		5								7
		*/
		root = new TreeNode();
		root->data = 50;

		TreeNode *newNode = new TreeNode();
		newNode->data = 25;
		root->left = newNode;

		newNode = new TreeNode();
		newNode->data = 66;
		root->right = newNode;

		newNode = new TreeNode();
		newNode->data = 11;
		root->left->left = newNode;

		newNode = new TreeNode();
		newNode->data = 33;
		root->left->right = newNode;

		newNode = new TreeNode();
		newNode->data = 45;
		root->right->left = newNode;

		newNode = new TreeNode();
		newNode->data = 88;
		root->right->right = newNode;

		newNode = new TreeNode();
		newNode->data = 5;
		root->left->left->left = newNode;

		newNode = new TreeNode();
		newNode->data = 7;
		root->right->right->right = newNode;

		// uncomment below code to make tree unbalanced.
		//newNode = new TreeNode();
		//newNode->data = 71;
		//root->right->right->right->right = newNode;		

	}	

	#pragma region Inefficient approach running in O(N^2)
	int getHeight(TreeNode *treeRoot)
	{
		if (treeRoot == NULL) return 0; // base case
		return max(getHeight(treeRoot->left),getHeight(treeRoot->right)) + 1;
	}

	bool isBalanced()
	{
		return isBalanced(root);
	}

	bool isBalanced(TreeNode *treeRoot)
	{
		if (treeRoot == NULL) return true; // base case

		int heightDiff = getHeight(root->left) - getHeight(root->right);
		if (abs(heightDiff) > 1)
		{
			return false;
		}
		else
		{
			return isBalanced(treeRoot->left) && isBalanced(treeRoot->right);
		}
	}
	#pragma endregion

#pragma region Efficient approach running in O(N) and O(H) space
	int checkHeight()
	{
		return checkHeight(root);
	}

	int checkHeight(TreeNode *treeRoot)
	{
		if (treeRoot == NULL)
			return 0;

		// check if left is balanced
		int leftHeight = checkHeight(treeRoot->left);
		if (leftHeight == -1)
			return -1; // not balanced

		// check if right is balanced
		int rightHeight = checkHeight(treeRoot->right);
		if (rightHeight == -1)
			return -1; // not balanced

		// check if current node is balanced
		int heightDiff = leftHeight - rightHeight;
		if (abs(heightDiff) > 1)
		{
			return -1; // not balanced
		}
		else
		{
			// return height
			return max(leftHeight, rightHeight) + 1;
		}
	}
#pragma endregion
};

int main()
{
	Tree *tree = new Tree();
	tree->BuildTree();

#pragma region inefficient way
	cout << "Inefficient way!!!" << endl;
	if (tree->isBalanced())
	{
		cout << "Balanced!!!" << endl;
	}
	else
	{
		cout << "Not balanced!!!" << endl;
	}
#pragma endregion

#pragma region efficient way
	cout << "Efficient way!!!" << endl;
	if (tree->checkHeight()==-1)
	{
		cout << "Not Balanced!!!" << endl;
	}
	else
	{
		cout << "Balanced!!!" << endl;
	}
#pragma endregion
}