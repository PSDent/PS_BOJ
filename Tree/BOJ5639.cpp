#include <iostream>
#include <string>

class BinarySearchTree
{
private:
	struct NODE
	{
		NODE *left;
		NODE *right;
		int val;
	};

	NODE *root;
	NODE **searchNode;

private:
	void Search(int val, NODE *node)
	{
		if (val > node->val)
		{
			if (node->right == NULL)
			{
				searchNode = &node->right;
				return;
			}
			else
				Search(val, node->right);
		}
		else if (val < node->val)
		{
			if (node->left == NULL)
			{
				searchNode = &node->left;
				return;
			}
			else
				Search(val, node->left);
		}
	}

public:	
	BinarySearchTree(int val) 
	{
		root = new NODE{ NULL, NULL, val };
	}
	~BinarySearchTree() {}

	void Insertion(int val)
	{
		Search(val, root);

		*searchNode = new NODE{ NULL, NULL, val };
	}

	void Traversal()
	{
		PostTraversal(root);
	}

	void PostTraversal(NODE *node)
	{
		if (node == NULL)
			return;

		PostTraversal(node->left);
		PostTraversal(node->right);
		std::cout << node->val << '\n';
	}

};

int main()
{
	std::string str;
	int input = 0;
	BinarySearchTree *tree;

	std::cin >> input;

	tree = new BinarySearchTree(input);

	while (!std::cin.eof())
	{
		std::cin >> input;
		tree->Insertion(input);
	}

	tree->Traversal();

	return 0;
}
