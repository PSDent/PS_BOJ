#include <iostream>
#include <queue>
#include <deque>
#include <cstring>

using Point = std::pair<int, int>;

std::queue<Point> virusQ;
std::deque<Point> wallQ;
int N, M, max = 0;
int wallCnt;
int map[8][8];
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

int Max(int a, int b)
{
	return a > b ? a : b;
}

void VirusBFS()
{
	bool visit[8][8];
	memset(visit, false, sizeof(visit));

	std::queue<Point> q(virusQ);
	int virusCnt = 0;

	while (!q.empty())
	{
		++virusCnt;
		Point point = q.front();
		q.pop();

		visit[point.second][point.first] = true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = point.first + dirX[i];
			int ny = point.second + dirY[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			bool check = false;
			for (int i = 0; i < 3; ++i)
			{
				if (wallQ[i].first == nx && wallQ[i].second == ny)
				{
					check = true;
					break;
				}
			}

			if (map[ny][nx] == 0 && visit[ny][nx] == false && !check)
			{
				visit[ny][nx] = true;
				q.emplace(nx, ny);
			}
		}
	}
	max = Max(max, (N * M - (virusCnt + wallCnt + 3) ));
}

void SetUpWall(int x, int y, int cnt)
{
	if (map[y][x] != 0)
		return;

	wallQ.emplace_back(x, y);

	if (cnt == 3)
	{
		VirusBFS();
		wallQ.pop_back();
		return;
	}

	int i = y;
	int j = 0;
	if (x + 1 < M)
		j = x + 1;
	else
		++i;
	for (; i < N; ++i)
	{
		for (; j < M; ++j)
		{
			SetUpWall(j, i, cnt + 1);
		}
		j = 0;
	}
	wallQ.pop_back();

	return;
}

int main()
{ 
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 1)
				++wallCnt;
			else if (map[i][j] == 2) 
				virusQ.emplace(j, i);
		}
	 
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			SetUpWall(j, i, 1);

	std::cout << max;
	return 0;
}
