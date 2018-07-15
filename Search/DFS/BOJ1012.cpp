#include <iostream>

using namespace std;

bool visit[50][50];
int farm[50][50];
int M, N, K, cnt = 0;

void DFS(int x, int y)
{
	if (visit[y][x])
		return;

	visit[y][x] = true;

	if (x < M - 1 && farm[y][x + 1] == 1)
		DFS(x + 1, y);
	if (x > 0 && farm[y][x - 1] == 1)
		DFS(x - 1, y);
	if (y < N - 1 && farm[y + 1][x] == 1)
		DFS(x, y + 1);
	if (y > 0 && farm[y - 1][x] == 1)
		DFS(x , y - 1);

	return;
}

int main()
{
	int T;
	int X, Y;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		for (int z = 0; z < N; ++z)
			for (int c = 0; c < M; ++c)
			{
				farm[z][c] = 0;
				visit[z][c] = false;
			}

		cin >> M >> N >> K;
		for (int j = 0; j < K; ++j)
		{
			cin >> X >> Y;
			farm[Y][X] = 1;
		}

		for (int m = 0; m < N; ++m)
		{
			for (int n = 0; n < M; ++n)
			{
				if (!visit[m][n] && farm[m][n] == 1)
				{
					DFS(n, m);
					++cnt;
				}
			}
		}

		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}
