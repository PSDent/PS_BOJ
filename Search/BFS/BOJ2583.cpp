#include <iostream>
#include <queue>
#include <algorithm>

typedef struct {
	int x1, y1;
	int x2, y2;
} RECT;

void BFS(std::pair<int, int>);
void FillRect();

RECT rect[101];
int map[101][101], index = 1; // 0 = 공백 1 = 섬 구역 & 방문 
int sizeMap[101] = { 0 };
int M, N, rectNum;

int main()
{
	// M = y, N = x;
	std::cin >> M >> N >> rectNum;

	for (int i = 1; i <= rectNum; i++)
	{
		std::cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
		rect[i].y1 = M - rect[i].y1;
		rect[i].y2 = M - rect[i].y2;
		rect[i].x1 += 1;
		rect[i].x2 += 1;
	}

	FillRect(); // 맵을 채우고 
	
	for (int i = 1; i <= M; i++) 
		for(int j = 1; j <= N; j++)
			if(map[i][j] == 0)
				BFS(std::pair<int, int>{j, i});

	std::cout << index - (sizeMap[0] > 0) << '\n';
	for (int i = 0; i < index - (sizeMap[0] > 0); ++i) {
		std::cout << sizeMap[i];
		if (i < index - (sizeMap[0] > 0) - 1)
			std::cout << ' ';
	}

	return 0;
}

void BFS(std::pair<int, int> startPos) 
{
	int size = 0;
	std::queue<std::pair<int, int>> q;
	q.push(startPos);
	map[startPos.second][startPos.first] = 1;

	while (!q.empty())
	{
		std::pair<int, int> coord = q.front();
		q.pop();
		int x = coord.first;
		int y = coord.second;

		++size;
		
		if (x + 1 <= N && map[y][x + 1] == 0) {
			q.push(std::pair<int, int> {x + 1, y});
			map[y][x + 1] = 1;
		}

		if (x - 1 > 0 && map[y][x - 1] == 0)
		{
			q.push(std::pair<int, int> {x - 1, y});
			map[y][x - 1] = 1;
		}

		if (y + 1 <= M && map[y + 1][x] == 0) {
			q.push(std::pair<int, int> {x, y + 1});
			map[y + 1][x] = 1;
		}

		if (y - 1 > 0 && map[y - 1][x] == 0) {
			q.push(std::pair<int, int> {x, y - 1});
			map[y - 1][x] = 1;
		}
	}

	sizeMap[index-1] = size;
	std::sort(sizeMap, sizeMap + index);
	++index;

	return;
}

void FillRect()
{
	for (int i = 1; i <= rectNum; ++i)
		for (int j = rect[i].y1; j > rect[i].y2; --j)
			for (int k = rect[i].x1; k < rect[i].x2; ++k)
				map[j][k] = 2;
	return;
}
