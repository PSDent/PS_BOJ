#include <iostream>
#include <vector>
#include <algorithm>

using Node = std::pair<int, int>; // 자식 노드, 가중치
std::vector<Node> vList[10001];
int N, maxNode = 0, maxLoad = 0;

int DFS(int v, int p)
{
	int max = 0, subMax = 0;

	for (int i = 0; i < vList[v].size(); ++i)
	{
		int val = DFS(vList[v][i].first, 0) + vList[v][i].second;
		if (val > max)
		{
			if (max > subMax)
				subMax = max;
			max = val;
		}
		else
			if (val > subMax)
				subMax = val;
	}

	if (max + subMax > maxLoad)
		maxLoad = max + subMax;

	return max;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;

	int a, b = 0, c;
	for(int i = 1; i < N; ++i)
	{
		std::cin >> a >> b >> c;
		maxNode = a;
		vList[a].emplace_back(Node(b, c));
	}

	DFS(1, 0);

	std::cout << maxLoad;

	return 0;
}
