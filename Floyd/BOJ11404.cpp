#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();
int dist[101][101];

int Min(int a, int b) { return a < b ? a : b; }

int main()
{
	int n, m;
	int a, b, c;
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		std::cin >> a >> b >> c;
		dist[a][b] = Min(dist[a][b], c);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if (dist[j][i] == INF || dist[i][k] == INF) continue;
				if (dist[j][i] + dist[i][k] < dist[j][k]) dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dist[i][j] == INF)
				std::cout << 0 << ' ';
			else
				std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}