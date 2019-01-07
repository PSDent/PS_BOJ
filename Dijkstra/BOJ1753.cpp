#include <iostream>
#include <queue>
#include <limits>
#include <functional>

const int INF = std::numeric_limits<int>::max();
using Point = std::pair<int, int>;

int V, E, K;
int dest[20001];
std::priority_queue<Point, std::vector<Point>, std::greater<Point>> pq;
std::vector<Point> inV[20001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int u, v, w;
	std::cin >> V >> E >> K;

	for (int i = 1; i <= 20000; ++i)
		dest[i] = INF;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> u >> v >> w;
		inV[u].emplace_back(w, v);
	}

	dest[K] = 0;
	pq.emplace(0, K);
	while (!pq.empty())
	{
		int srtIndex = pq.top().second;
		int srtDist = pq.top().first;
		pq.pop();

		if (dest[srtIndex] < srtDist) continue;

		for (int i = 0; i < inV[srtIndex].size(); ++i)
		{
			int destIndex = inV[srtIndex][i].second;
			int destDist = inV[srtIndex][i].first;

			if (dest[destIndex] > srtDist + destDist)
			{
				dest[destIndex] = srtDist + destDist;
				pq.emplace(dest[destIndex], destIndex);
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dest[i] == INF) std::cout << "INF" << '\n';
		else std::cout << dest[i] << ' ' << '\n';
	}

	return 0;
}
