#include <iostream>

bool tree[50][50];
int N, cut;

int Traversial(int node)
{
	bool isLeaf = true;
	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		if (tree[node][i] && i != cut)
		{
			isLeaf = false;
			cnt += Traversial(i);
		}
	}

	return (isLeaf ? 1 : 0) + cnt;
}

int main()
{
	int root;
	std::cin >> N;

	int input;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;

		if (input == -1) 
			root = i;
		else
			tree[input][i] = true;
	}
	std::cin >> cut;
	if (root != cut)
		std::cout << Traversial(root);
	else
		std::cout << 0;

	return 0;
}
