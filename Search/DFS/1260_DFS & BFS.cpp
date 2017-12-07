//================================================
// Filename : 1260_DFS & BFS
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1260
//================================================
#include <iostream>

int N, M, V;
bool Matrix[1001][1001] = { false };

void BFS(int v)
{
	bool visited2[1001] = { false };
	int queue[1001], rear = 0, front = 0;
	int pop;

	queue[++rear] = v;
	visited2[v] = true;

	while (front < rear)
	{
		pop = queue[++front];
		std::cout << pop << ' ';

		for (int i = 1; i <= N; i++)
			if (Matrix[pop][i] && !visited2[i]) {
				queue[++rear] = i;
				visited2[i] = true;
			}
	}

	return;
}

void DFS(int v)
{
	static bool visited[1001] = { false };
	visited[v] = true;
	std::cout << v << ' ';

	for (int i = 1; i <= N; i++)
		if (Matrix[v][i] && !visited[i])
			DFS(i);

	return;
}

int main()
{
	std::cin >> N >> M >> V;

	int x, y;
	for (int i = 0; i < M; i++)
	{
		std::cin >> x >> y;
		Matrix[x][y] = true;
		Matrix[y][x] = true;
	}

	DFS(V);
	std::cout << std::endl;
	BFS(V);

	return 0;
}