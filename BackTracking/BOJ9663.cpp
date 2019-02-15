#include <iostream>

int map[16][16];
int N, total = 0;

//void DFS(int x, int y, int cnt)
//{
//	if (map[y][x]) return;
//	if (cnt == N)
//	{
//		++total; return;
//	}
//
//	map[y][x] = cnt;
//	for (int i = 1; i <= N; ++i)
//	{
//		int left = x - i;
//		int up = y - i;
//		int right = x + i;
//		int down = y + i;
//
//		if (left > 0)
//		{
//			if (!map[y][left]) map[y][left] = cnt;
//			if (up > 0 && !map[up][left]) map[up][left] = cnt;
//			if (down <= N && !map[down][left]) map[down][left] = cnt;
//		}
//		if (right <= N)
//		{
//			if (!map[y][right]) map[y][right] = cnt;
//			if (up > 0 && !map[up][right]) map[up][right] = cnt;
//			if (down <= N && !map[down][right]) map[down][right] = cnt;
//		}
//		if (up > 0 && !map[up][x])
//		{
//			map[up][x] = cnt;
//		}
//		if (down <= N && !map[down][x])
//		{
//			map[down][x] = cnt;
//		}
//	}
//
//	for (int i = y; i <= N; ++i)
//	{
//		for (int j = 1; j <= N; ++j)
//		{
//			DFS(j, i, cnt + 1);
//		}
//	}
//
//	map[y][x] = 0;
//	for (int i = 1; i <= N; ++i)
//	{
//		int left = x - i;
//		int up = y - i;
//		int right = x + i;
//		int down = y + i;
//
//		if (left > 0)
//		{
//			if (map[y][left] == cnt)
//				map[y][left] = 0;
//			if (up > 0 && map[up][left] == cnt) map[up][left] = 0;
//			if (down <= N && map[down][left] == cnt) map[down][left] = 0;
//		}
//		if (right <= N)
//		{
//			if (map[y][right] == cnt) map[y][right] = 0;
//			if (up > 0 && map[up][right] == cnt) map[up][right] = 0;
//			if (down <= N && map[down][right] == cnt) map[down][right] = 0;
//		}
//		if (up > 0 && map[up][x] == cnt)
//		{
//			map[up][x] = 0;
//		}
//		if (down <= N && map[down][x] == cnt)
//		{
//			map[down][x] = 0;
//		}
//	}
//
//}

void DFS(int x, int y, int cnt)
{
	if (map[y][x]) return;

	for (int i = 1; i <= N; ++i)
	{
		int left = x - i;
		int up = y - i;
		int right = x + i;
		int down = y + i;

		if (left > 0)
		{
			if (map[y][left]) return; 
			if (up > 0 && map[up][left]) return;
			if (down <= N && map[down][left]) return;
		}
		if (right <= N)
		{
			if (map[y][right]) return;
			if (up > 0 && map[up][right]) return;
			if (down <= N && map[down][right]) return;
		}
		if (up > 0 && map[up][x]) return;
		if (down <= N && map[down][x]) return;
	}
	map[y][x] = cnt;

	if (cnt == N)
	{
		map[y][x] = 0;
		++total; return;
	}

	for (int i = 1; i <= N; ++i)
		DFS(i, y + 1, cnt + 1);
	map[y][x] = 0;
}

int main()
{
	std::cin >> N;
	int prev = 0;

	for (int i = 1; i <= N / 2; ++i)
		DFS(i, 1, 1);
	total *= 2;
	if (N % 2 == 1)
		DFS(N / 2 + 1, 1, 1);
	std::cout << total;

	return 0;
}