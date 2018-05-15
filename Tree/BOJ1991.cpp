#include <iostream>

class BinaryTree
{
public:
	struct Node
	{
		Node *leftNode = NULL;
		Node *rightNode = NULL;
		char name;

		Node(char name, Node *leftNode, Node *rightNode)
		{
			this->name = name;
			this->leftNode = leftNode;
			this->rightNode = rightNode;
		}
	};

public:
	BinaryTree()
	{
		root = new Node('A', NULL, NULL);
	}

	~BinaryTree()
	{

	}

	void Travisial()
	{
		PreOrder(root);
		std::cout << '\n';
		InOrder(root);
		std::cout << '\n';
		PostOrder(root);
		std::cout << '\n';
	}

	void Insertion(char node, char left, char right)
	{
		Search(root, node); 

		if(left != '.') 
			cacheNode->leftNode = new Node(left, NULL, NULL);
		if(right != '.')
			cacheNode->rightNode = new Node(right, NULL, NULL);
	}

	void Search(Node *node, char name)
	{
		if (node == NULL)
			return;

		if (node->name == name)
		{
			cacheNode = node;
			return;
		}
		else
		{
			Search(node->leftNode, name);
			Search(node->rightNode, name);
		}
	}

private:
	void PreOrder(Node *node)
	{
		if (node == NULL)
			return;

		std::cout << node->name;
		PreOrder(node->leftNode);
		PreOrder(node->rightNode);
	}

	void InOrder(Node *node)
	{
		if (node == NULL)
			return;

		InOrder(node->leftNode);
		std::cout << node->name;
		InOrder(node->rightNode);
	}

	void PostOrder(Node *node)
	{
		if (node == NULL)
			return;

		PostOrder(node->leftNode);
		
		PostOrder(node->rightNode);
		std::cout << node->name;
	}

private:
	Node *root;
	Node *cacheNode;
};

int main()
{
	BinaryTree *tree = new BinaryTree;

	int N;
	char node, left, right;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> node >> left >> right;
		tree->Insertion(node, left, right);
	}

	tree->Travisial();

	return 0;
}