#include <iostream>
#include <queue>
#include <limits>
#include <functional>

const int INF = std::numeric_limits<int>::max();
using Point = std::pair<int, int>;

int V, E, K;
int dest[20001];
std::priority_queue<Point> pq;
std::vector<Point> inV[20001];
bool visit[20001];

int main()
{
	int u, v, w;
	std::cin >> V >> E >> K;

	for (int i = 1; i <= 20000; ++i)
		dest[i] = INF;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> u >> v >> w;
		inV[u].push_back(std::make_pair(v, w));
	}

	dest[K] = 0;
	pq.emplace(K, 0);
	while (!pq.empty())
	{
		int srtIndex = pq.top().first;
		int srtDist = pq.top().second;
		pq.pop();

		for (int i = 0; i < inV[srtIndex].size(); ++i)
		{
			int destIndex = inV[srtIndex][i].first;
			int destDist = inV[srtIndex][i].second;
			
			if (dest[destIndex] > srtDist + destDist)
			{
				dest[destIndex] = srtDist + destDist;
				pq.emplace(destIndex, dest[destIndex]);
			}
		}
		visit[srtIndex] = true;
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dest[i] == INF)
			std::cout << "INF" << '\n';
		else
			std::cout << dest[i] << ' ' << '\n';
	}

	return 0;
}