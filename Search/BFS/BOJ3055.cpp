#include <iostream>
#include <queue>

using Point = std::pair<short, short>;

int R, C;
char map[51][51];
short dirX[4] = { 0, 1, 0, -1 };
short dirY[4] = { -1, 0, 1, 0 };
bool visit[51][51];
std::queue <Point> waterQ;
std::queue <Point> hedgeQ;
int startX, startY;
int minTime = 5000;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	std::cin >> R >> C;

	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				hedgeQ.push(std::make_pair(j, i));
				map[i][j] = '.';
			}
			else if (map[i][j] == '*')
				waterQ.push(std::make_pair(j, i));
		}
		
	int time = 0;
	Point point;
	while (!hedgeQ.empty())
	{
		int prevSize = waterQ.size();
		for (int i = 0; i < prevSize; ++i)
		{
			point = waterQ.front();
			waterQ.pop();

			map[point.second][point.first] = '*';

			for (int i = 0; i < 4; ++i)
			{
				int nx = point.first + dirX[i];
				int ny = point.second + dirY[i];

				if (nx > C || nx < 1 || ny > R || ny < 1)
					continue;

				if (map[ny][nx] == '.')
				{
					map[ny][nx] = '@';
					waterQ.push(std::make_pair(nx, ny));
				}
			}
		}

		prevSize = hedgeQ.size();
		for (int i = 0; i < prevSize; ++i)
		{
			point = hedgeQ.front();
			hedgeQ.pop();
				
			if (map[point.second][point.first] == 'D')
				minTime = Min(minTime, time);
			visit[point.second][point.first] = true; 

			for (int i = 0; i < 4; ++i)
			{
				int nx = point.first + dirX[i];
				int ny = point.second + dirY[i];

				if (nx > C || nx < 1 || ny > R || ny < 1)
					continue;

				if ((map[ny][nx] == '.' || map[ny][nx] == 'D') && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					hedgeQ.push(std::make_pair(nx, ny));
				}
			}
		}
		++time;
	}

	if (minTime == 5000)
		std::cout << "KAKTUS";
	else
		std::cout << minTime;
	return 0;
}
