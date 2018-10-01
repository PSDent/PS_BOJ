#include <iostream>
#include <queue>
#include <limits>

using Point = std::pair<long, long>;

std::vector<Point> v[801];
std::priority_queue<Point> pq;
long dest[801][801];
long INF = std::numeric_limits<long>::max();

int Min(long a, long b) { return a < b ? a : b; }

void Dijkstra(int vertex)
{
	dest[vertex][vertex] = 0;
	pq.push(std::make_pair(vertex, 0));
	while (!pq.empty())
	{
		int nowIndex = pq.top().first;
		int nowDist = pq.top().second;
		pq.pop();

		for (unsigned int i = 0; i < v[nowIndex].size(); ++i)
		{
			long destIndex = v[nowIndex][i].first;
			long destDist = v[nowIndex][i].second;
			if (nowDist + destDist < dest[vertex][destIndex])
			{
				dest[vertex][destIndex] = nowDist + destDist;
				pq.push(std::make_pair(destIndex, nowDist + destDist));
			}
		}
	}
}

int main()
{
	int N, E;
	int a, b, c;
	int d1, d2;

	std::cin >> N >> E;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			dest[i][j] = INF;

	for (int i = 0; i < E; ++i)
	{
		std::cin >> a >> b >> c;
		v[b].push_back(std::make_pair(a, c));
		v[a].push_back(std::make_pair(b, c));
	}
	std::cin >> d1 >> d2;
	Dijkstra(1);
	Dijkstra(N);
	Dijkstra(d1);
	Dijkstra(d2);

	long r1 = dest[1][d1] + dest[d1][d2] + dest[d2][N];
	long r2 = dest[1][d2] + dest[d2][d1] + dest[d1][N];

	if (dest[d1][d2] == INF && dest[d2][d1] == INF)
		std::cout << -1;
	else
		std::cout << Min(r1, r2);
	return 0;
}
