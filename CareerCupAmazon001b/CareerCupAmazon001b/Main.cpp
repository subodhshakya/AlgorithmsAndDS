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
	vector<Node*> childrens; //use this in case of N-ary tree.
	void AddChildren(int childNodeValue)
	{
		Node *childNode = new Node();
		childNode->data = childNodeValue;

		childrens.push_back(childNode);
	}
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
			45	20  5		10		20
		45	      20   5   5  5   20

		*/
		if (root == NULL)
		{
			root = new Node();
			root->data = 100;
		}
		
		root->AddChildren(70);
		root->AddChildren(30);

		root->childrens[0]->AddChildren(45);
		root->childrens[0]->AddChildren(20);
		root->childrens[0]->AddChildren(5);

		root->childrens[1]->AddChildren(10);
		root->childrens[1]->AddChildren(20);

		root->childrens[0]->childrens[0]->AddChildren(45);
		root->childrens[0]->childrens[1]->AddChildren(20);
		root->childrens[0]->childrens[2]->AddChildren(5);

		root->childrens[1]->childrens[0]->AddChildren(5);
		root->childrens[1]->childrens[0]->AddChildren(5);

		root->childrens[1]->childrens[1]->AddChildren(20);		
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
		int childSum = 0;
		
		if (node->childrens.size()>0)
		{
			for (int i = 0; i < node->childrens.size(); i++)
			{
				childSum += node->childrens[i]->data;
			}

			if (parentValue != childSum)
			{
				holdSumProperty = false;
				return;
			}
		}

		// PreOrder Traversal;
		for (int i = 0; i < node->childrens.size(); i++)
		{
			SumProperty(node->childrens[i]);
		}		
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