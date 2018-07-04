#include <iostream>
#include <queue>

std::queue < std::pair<int, int> > q;
int board[1000][1000];
int M, N, cnt = -1; // M = 가로, N = 세로

int BFS(std::pair<int, int> pos)
{
	int nextCnt = 0;
	int x = pos.second;
	int y = pos.first;

	if (x > 0 && board[y][x - 1] == 0)
	{
		q.push(std::pair<int, int>{ y, x - 1}); 
		board[y][x - 1] = 1;
		++nextCnt;
	}

	if (x < M - 1 && board[y][x + 1] == 0)
	{
		q.push(std::pair<int, int>{ y, x + 1});
		board[y][x + 1] = 1;
		++nextCnt;
	}

	if (y > 0 && board[y - 1][x] == 0)
	{
		q.push(std::pair<int, int>{ y - 1, x});
		board[y - 1][x] = 1;
		++nextCnt;
	}

	if (y < N - 1 && board[y + 1][x] == 0)
	{
		q.push(std::pair<int, int>{ y + 1, x});
		board[y + 1][x] = 1;
		++nextCnt;
	}

	return nextCnt;
}

bool CheckRaw()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (board[i][j] == 0)
				return false;
	return true;
}

int main()
{
	int queueCnt = 0;

	std::cin >> M >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			std::cin >> board[i][j];

			if (board[i][j] == 1)
			{
				++queueCnt;
				std::pair<int, int> val;
				val.first = i;
				val.second = j;
				q.push(val);
			}
		}

	while (!q.empty())
	{
		int elementCnt = queueCnt;
		queueCnt = 0;
		for (int i = 0; i < elementCnt; ++i)
		{
			queueCnt += BFS(q.front());
			q.pop();
		}
		++cnt;
	}

	if (cnt == -1 && CheckRaw())
		cnt = 0;
	else if (cnt > -1 && !CheckRaw())
		cnt = -1;

	std::cout << cnt;

	return 0;
}
