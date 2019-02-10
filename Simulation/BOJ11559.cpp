#include <iostream>
#include <cstring>
#include <queue>

using Point = std::pair<int, int>;
int dirX[4] = { 0, 1, 0, -1 }, dirY[4] = { -1, 0, 1, 0 };
bool visit[13][7];
char map[13][7];
std::queue<Point> rq;

void Gravity()
{
	for (int i = 11; i >= 1; --i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			int x = j, y = i;
			while (map[y + 1][x] == '.')
			{
				map[y + 1][x] = map[y][x];
				map[y][x] = '.';
				++y;
			}
		}
	}
}

int Search(char color, int x, int y)
{
	if (map[y][x] != color || visit[y][x]) return 0;
	if (x > 6 || x < 1 || y > 12 || y < 1) return 0;

	visit[y][x] = true;
	rq.emplace(x, y);

	int cnt = 1;
	for (int i = 0; i < 4; ++i)
		cnt += Search(color, x + dirX[i], y + dirY[i]);

	return cnt;
}

int main()
{
	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 6; ++j)
			std::cin >> map[i][j];

	int combo = 0, prevCombo = -1;

	while (prevCombo != combo)
	{
		bool isCombo = false;
		for (int i = 1; i <= 12; ++i)
		{
			for (int j = 1; j <= 6; ++j)
			{
				int amount;
				if (map[i][j] != '.')
				{
					amount = Search(map[i][j], j, i);
					if (amount >= 4)
					{
						isCombo = true;
						while (!rq.empty())
						{
							Point p = rq.front(); rq.pop();
							int x = p.first, y = p.second;
							map[y][x] = '.';
						}
					}
					else
						while (!rq.empty())
							rq.pop();
				}
			}
		}
		prevCombo = combo;
		if (isCombo)
		{
			for(int i = 1; i <= 12; ++i)
				memset(visit[i], false, sizeof(visit[i]));
			Gravity();
			++combo;
		}
	}

	std::cout << combo;

	return 0;
}
