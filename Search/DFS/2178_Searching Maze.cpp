//================================================
// Filename : 2178_Seaching Maze
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2178
//================================================
#include <iostream>
#include <queue>
#include <string>

// N x M
short map[100][100];
short visited[100][100];
short minCnt, N, M;
std::queue<std::pair<short, short>>q;

void BFS()
{
	// 큐가 공백(empty)일 때까지 반복한다.
	// 큐가 공백일때까지 N,M 에 도달하지 못하면 길이 없는 것임.
	while (!q.empty())
	{
		// 임시 컨테이너 path에 front 컨테이너를 넣고 pop.
		std::pair<short, short> block = q.front();
		q.pop();

		if (map[block.second][block.first + 1] != 0 && block.first + 1 <= M) // Right
			if (!visited[block.second][block.first + 1])
			{
				map[block.second][block.first + 1] = map[block.second][block.first] + 1;
				visited[block.second][block.first + 1] = 1;
				q.push(std::pair<short, short>(block.first + 1, block.second));
			}

		if (map[block.second][block.first - 1] != 0 && block.first - 1 >= 0) // Left
			if (!visited[block.second][block.first - 1])
			{
				map[block.second][block.first - 1] = map[block.second][block.first] + 1;
				visited[block.second][block.first - 1] = 1;
				q.push(std::pair<short, short>(block.first - 1, block.second));
			}

		if (map[block.second - 1][block.first] != 0 && block.second - 1 >= 0) // Up
			if (!visited[block.second - 1][block.first])
			{
				map[block.second - 1][block.first] = map[block.second][block.first] + 1;
				visited[block.second - 1][block.first] = 1;
				q.push(std::pair<short, short>(block.first, block.second - 1));
			}

		if (map[block.second + 1][block.first] != 0 && block.second + 1 <= N) // Down
			if (!visited[block.second + 1][block.first])
			{
				map[block.second + 1][block.first] = map[block.second][block.first] + 1;
				visited[block.second + 1][block.first] = 1;
				q.push(std::pair<short, short>(block.first, block.second + 1));
			}
	}

}

int main()
{
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		std::string temp;
		std::cin >> temp;
		for (int j = 0; j < M; j++)
			map[i][j] = temp[j] - 48;
	}
	--N; --M;

	q.push(std::pair<short, short>(0, 0));

	BFS();
	std::cout << map[N][M];

	return 0;
}
