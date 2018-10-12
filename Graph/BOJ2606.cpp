#include <iostream>

int N, M;
bool visit[101];
bool computer[101][101];
bool virus[101];

void DFS(int v)
{
	if (visit[v])
		return;

	visit[v] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (virus[v] && computer[v][i])
		{
			virus[i] = true;
			DFS(i);
		}
	}
}

int main()
{
	int a, b;
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> a >> b;
		computer[a][a] = computer[b][b] = true;
		computer[a][b] = computer[b][a] = true;
	}

	int cnt = 0;
	virus[1] = true;
	for (int i = 1; i <= N; ++i) DFS(i);

	for (int i = 2; i <= N; ++i)
		if (virus[i]) { ++cnt; }
	std::cout << cnt;

	return 0;
}
