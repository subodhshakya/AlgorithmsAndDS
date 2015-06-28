/*
sum property is as follows:
For every node, value stored in it must be equal to sum of values in left and right child. Consider value as 0 for NULL children.
e.g. parent = 10, left child = 8 and right child = 2 then sum property satisfied. parent = left + right. in this case return true
e.g. parent = 10, left child = 7 and right child = 2 then sum property failed. parent != left + right. in this case return false
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	//vector<Node*> childrens; //use this in case of N-ary tree.
};

class Tree
{
	Node *root;
	bool holdSumProperty;
public:
	Tree()
	{
		root = NULL;
	}

	void BuildTree()
	{
		/*
						100
				70				30
			45		25		10		20
		45	      20   5   5  5   20

		*/
		if (root == NULL)
		{
			root = new Node();
			root->data = 100;
		}
		Node *newNode = new Node();
		newNode->data = 70;
		root->left = newNode;

		newNode = new Node();
		newNode->data = 30;
		root->right = newNode;

		newNode = new Node();
		newNode->data = 45;
		root->left->left = newNode;

		newNode = new Node();
		newNode->data = 25;
		root->left->right = newNode;

		newNode = new Node();
		newNode->data = 10; // violate sum.
		root->right->left= newNode;

		newNode = new Node();
		newNode->data = 20;
		root->right->right = newNode;

		newNode = new Node();
		newNode->data = 45;
		root->left->left->left= newNode;

		newNode = new Node();
		newNode->data = 20;
		root->left->right->left = newNode;

		newNode = new Node();
		newNode->data = 5;
		root->left->right->right = newNode;

		newNode = new Node();
		newNode->data = 5;
		root->right->left->left= newNode;

		newNode = new Node();
		newNode->data = 5;
		root->right->left->right = newNode;

		newNode = new Node();
		newNode->data = 20;
		root->right->right->left= newNode;
	}

	bool SumProperty()
	{
		holdSumProperty = true;
		SumProperty(root);
		return holdSumProperty;
	}

	void SumProperty(Node *node)
	{
		// Error handling
		if (root == NULL)
		{
			throw "Tree is empty";
		}

		if (node == NULL)
		{
			return;
		}

		int parentValue = node->data;
		int leftChildValue;
		int rightChildValue;
		if (!(node->left == NULL&&node->right == NULL))
		{
			if (node->left == NULL)
			{
				leftChildValue = 0;
			}
			else
			{
				leftChildValue = node->left->data;
			}

			if (node->right == NULL)
			{
				rightChildValue = 0;
			}
			else
			{
				rightChildValue = node->right->data;
			}

			if (parentValue != (leftChildValue + rightChildValue))
			{
				holdSumProperty = false;
				return;
			}
		}		

		// PreOrder Traversal;
		SumProperty(node->left);
		SumProperty(node->right);
	}
};

int main()
{
	Tree *myTree = new Tree();
	myTree->BuildTree();
	if (myTree->SumProperty())
	{
		cout << "hold sum property." << endl;
	}
	else
	{
		cout << "doesn't hold sum property." << endl;
	}
}