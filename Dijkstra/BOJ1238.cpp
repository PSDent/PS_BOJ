#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using Point = std::pair<int, int>;

const int INF = std::numeric_limits<int>::max();
int dest[1001][10001];
std::vector<Point> v[10001];
std::priority_queue<Point> pq;

int main()
{
	int N, M, X;
	int s, e, d;
	int max = 0;

	std::cin >> N >> M >> X;
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
			dest[i][j] = INF;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> s >> e >> d;
		v[s].push_back(std::make_pair(e, d));
	}

	for (int i = 1; i <= N; ++i)
	{
		dest[i][i] = 0;
		pq.push(std::make_pair(i, 0));
		while (!pq.empty())
		{
			int destEdge = pq.top().first;
			int destDist = pq.top().second;
			pq.pop();

			for (int j = 0; j < v[destEdge].size(); ++j)
			{
				int nowEdge = v[destEdge][j].first;
				int nowDist = v[destEdge][j].second;

				if (destDist + nowDist < dest[i][nowEdge])
				{
					dest[i][nowEdge] = destDist + nowDist;
					pq.push(std::make_pair(nowEdge, dest[i][nowEdge]));
				}
			}
		}
	}
	
	for (int i = 1; i <= N; ++i)
	{
		int total = dest[i][X] + dest[X][i];
		max = total > max ? total : max;
	}
	std::cout << max;
	return 0;
}
