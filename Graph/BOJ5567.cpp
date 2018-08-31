#include <iostream>

bool friends[501][501];
bool visit[501];
int N, M, inviteCnt;

void DFS(int v, int cnt)
{
	visit[v] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (cnt < 3 && friends[v][i] && i != v)
		{
			visit[i] = true;
			DFS(i, cnt + 1);
		}
	}
}

int main()
{
	int input1, input2;

	std::cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> input1 >> input2;
		friends[input1][input2] = true;
		friends[input2][input1] = true;
	}

	DFS(1, 1);

	for (int i = 2; i <= N; ++i)
		if (visit[i])
			++inviteCnt;
	std::cout << inviteCnt;

	return 0;
}
