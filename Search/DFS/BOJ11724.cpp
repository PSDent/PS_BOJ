#include <iostream>

int cnt = 0, N, M;
bool visit[1001];
bool node[1001][1001];

void DFS(int v)
{
	visit[v] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (node[v][i] && !visit[i])
		{
			DFS(i);
		}
	}

	return;
}

int main()
{
	int input1, input2;

	std::cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> input1 >> input2;
		node[input1][input2] = true;
		node[input2][input1] = true;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!visit[i])
		{
			DFS(i);
			++cnt;
		}
	}

	std::cout << cnt;
}
