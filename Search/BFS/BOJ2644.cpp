#include <iostream>
#include <queue>

//using Point = std::pair<int, int>;
bool family[101][101];
bool visited[101];

int main()
{
	int N, a, b, m;

	std::cin >> N >> a >> b >> m;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		family[x][y] = true;
		family[y][x] = true;
	}

	std::queue<int> q;
	q.push(a);

	int nextLen = 0, nowLen = 1, cnt = 0, level = 0;
	while (!q.empty())
	{
		int current = q.front(); q.pop();
		visited[current] = true;

		if (current == b)
		{
			std::cout << level;
			return 0;
		}

		int localCnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i] && family[current][i])
			{
				visited[i] = true;
				q.push(i);
				++localCnt;
			}
		}
		nextLen += localCnt;

		++cnt;
		if (cnt == nowLen)
		{
			++level;
			nowLen += nextLen;
			nextLen = 0;
		}
	}

	std::cout << -1;

	return 0;
}
