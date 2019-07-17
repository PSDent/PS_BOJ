#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using BuildList = std::vector<int>;
int D[100001];
int visited[1001];

int Search(int node, BuildList *list)
{
	if (visited[node] >= 0) return visited[node];

	int maxTime = 0;
	for (int i = 0; i < list[node].size(); ++i)
	{
		int require = list[node][i];
		maxTime = std::max(maxTime, Search(require, list));
	}

	visited[node] = maxTime + D[node];

	return maxTime + D[node];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
	{
		int N, K, W;
		std::cin >> N >> K;

		for (int i = 1; i <= N; ++i)
			std::cin >> D[i];

		BuildList list[1001];
		for (int i = 1; i <= K; ++i)
		{
			int x, y;
			std::cin >> x >> y;
			list[y].emplace_back(x);
		}
		std::cin >> W;

		memset(visited, -1, sizeof(visited));
		std::cout << Search(W, list) << '\n';
	}

	return 0;
}