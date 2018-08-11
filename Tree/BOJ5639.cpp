#include <iostream>

struct Node
{
	int data;
	Node *lNode;
	Node *rNode;
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}

	void Insertion(int data)
	{
		if (data == EOF)
			return;

		Node *tNode = new Node;
		tNode->data = data;
		tNode->lNode = NULL;
		tNode->rNode = NULL;

		Search(&root, tNode);
	}

	void Traversal()
	{
		Post_Traversal(root);
	}

private:
	void Search(Node **node, Node *insert)
	{
		if (*node == NULL)
		{
			*node = insert;
			return;
		}

		if ((*node)->data < insert->data)
			Search(&(*node)->rNode, insert);
		else
			Search(&(*node)->lNode, insert);
	}

	void Post_Traversal(Node *node)
	{
		if(node == NULL)
			return;

		Post_Traversal(node->lNode);
		Post_Traversal(node->rNode);
		std::cout << node->data << '\n';
	}

private:
	Node *root;
};

int main()
{
	Tree tree;
	int input = 0;

	while (true)
	{
		std::cin >> input;
		if (std::cin.eof())
			break;
		tree.Insertion(input);
	}

	tree.Traversal();

	return 0;
}
