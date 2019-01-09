#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>

struct Point
{
	int x, y;
	int dist;
	
	Point(int x, int y, int dist) : x(x), y(y), dist(dist) {};
};

struct cmp
{
	bool operator()(Point a, Point b)
	{
		return a.dist > b.dist;
	}
};

std::vector<Point> maze[101][101];
std::priority_queue<Point, std::vector<Point>, cmp> pq;
int dest[101][101];
char map[101][101];
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };
const int limit = std::numeric_limits<int>::max();

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;

	std::cin >> M >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			dest[i][j] = limit;
			std::cin >> map[i][j];
		}
	}

	pq.emplace(1, 1, 0);
	dest[1][1] = 0;

	while (!pq.empty())
	{
		Point srt = pq.top(); pq.pop();

		if (srt.dist > dest[srt.y][srt.x]) continue;

		for (int i = 0; i < 4; ++i)
		{
			int dx = srt.x + dirX[i];
			int dy = srt.y + dirY[i];

			if (dx > 0 && dy > 0 && dx <= M && dy <= N)
			{
				int val = map[dy][dx] - '0';
				
				if (dest[dy][dx] > srt.dist + val)
				{
					dest[dy][dx] = srt.dist + val;
					pq.emplace(dx, dy, dest[dy][dx]);
				}
			}
		}
	}

	std::cout << dest[N][M];

	return 0;
}
