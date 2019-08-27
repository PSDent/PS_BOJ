#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[101];
int dist[101][101];
int N, M;

int main()
{
	cin >> N >> M;

	while (M--)
	{
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	
	for (int i = 1; i <= N; ++i)
	{
		queue<int> q; q.push(i);

		int levelNodes = 1, distVal = 1;
		bool visited[101];
		memset(visited, false, sizeof(visited));

		for (int j = 1; j <= N; ++j)
			dist[i][j] = 99999;

		while (!q.empty())
		{
			int now = q.front(); q.pop();
			--levelNodes;
			visited[now] = true;

			for (int j = 0; j < v[now].size(); ++j)
			{
				int next = v[now][j];
				if (!visited[next])
				{
					dist[i][next] = min(distVal, dist[i][next]);
					q.push(next);
				}
			}

			if (levelNodes == 0)
			{
				levelNodes = q.size();
				++distVal;
			}
		}
	}

	int minCnt = 99999999, minNo;
	for (int i = 1; i <= N; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= N; ++j)
			cnt += dist[i][j];

		if (cnt < minCnt)
		{
			minCnt = cnt;
			minNo = i;
		}
	}

	cout << minNo;

	return 0;
}
