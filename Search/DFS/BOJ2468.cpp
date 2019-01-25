#include <iostream>
#include <algorithm>
#include <list>

using Point = std::pair<int, int>; // x, y;
std::list<Point> list;
int map[101][101];
int water = 0, max = 0, N;
int dirX[4] = { 0, 1, 0, - 1 }, dirY[4] = { -1, 0, 1, 0 };
bool visited[101][101][101];

void DFS(int x, int y)
{
	if (x < 1 || x > N || y < 1 || y > N || map[y][x] <= water || visited[water][y][x])
		return;

	visited[water][y][x] = true;

	for (int i = 0; i < 4; ++i)
		DFS(x + dirX[i], y + dirY[i]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			std::cin >> map[i][j];
			list.emplace_back(j, i);
		}
	}
	
	while (!list.empty())
	{
		std::list<Point>::iterator iter;
		int cnt = 0;

		for (iter = list.begin(); iter != list.end();)
		{
			int x = iter->first, y = iter->second;
			if (map[y][x] <= water)
			{
				iter = list.erase(iter);
				continue;
			}
			else if (!visited[water][y][x])  
			{
				DFS(x, y);
				++cnt;
			}
			++iter;
		}

		++water;
		max = std::max(max, cnt);
	}

	std::cout << max;
	return 0;
}
