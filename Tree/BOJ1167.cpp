#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using Node = std::pair<int, int>;
std::vector<Node> tree[100001];
std::vector<bool> visited[100001];

#define Node first
#define Dist second

int V, max;

int DFS(int prevNode, int nowNode, int dist)
{
	bool visited[100001]; 
	memset(visited, false, sizeof(visited));
	visited[prevNode] = true;

	int firstMax = 0, secondMax = 0;

	for (int i = 0; i < tree[nowNode].size(); ++i)
	{
		if (visited[tree[nowNode][i].Node]) continue;

		int val = DFS(nowNode, tree[nowNode][i].Node, tree[nowNode][i].Dist);
		
		if (val > firstMax)
		{
			secondMax = firstMax;
			firstMax = val;
		}
		else if (val > secondMax) secondMax = val;
	}

	max = std::max(max, firstMax + secondMax);

	return firstMax + dist;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> V;

	for (int i = 0; i < V; ++i)
	{
		int nodeNum, cnt = 0;
		std::cin >> nodeNum;

		while (true)
		{
			int node, dist;
			std::cin >> node;
			if (node == -1) break;
			std::cin >> dist;

			++cnt;
			tree[nodeNum].emplace_back(std::make_pair(node, dist));
		}
	}

	DFS(0, 1, 0);
	std::cout << max;

	return 0;
}
