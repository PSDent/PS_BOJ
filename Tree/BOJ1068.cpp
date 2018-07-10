// 리프 노드 삭제시 반영이 안됨.
#include <iostream>

int node[50][51];
int cnt = 0, N, removeNode;

using namespace std;

void treeTraversal(int v)
{
	if (v == removeNode)
		return;

	if (node[v][50] == 0) // 자식노드가 없다면 
	{
		++cnt; // 리프노드 개수 + 1
		return;
	}

	for (int i = 0; i < N; i++)
		if (node[v][i] == 1)
			treeTraversal(i);
	return;
}

void cutLeaf()
{
	for (int i = 0; i < N; i++)
		if (node[i][removeNode] == 1)
			node[i][50] -= 1;
}

int main()
{
	int temp, root;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == -1)
		{
			root = i;
			temp = i;
		}
		else
			node[temp][i] = 1;
		++node[temp][50];
	}

	cin >> removeNode;
	cutLeaf();

	treeTraversal(root);

	cout << cnt;

	return 0;
}
