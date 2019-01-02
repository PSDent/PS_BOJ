#include <iostream>
#include <cmath>

bool tri[4000][10000];
int maxLevel, N;

struct Point
{
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x, y;
};

void PolyTriangle(Point top, Point left, Point right, int level)
{
	if (level > maxLevel)
		return;

	for (int i = 0; top.x - i > left.x; ++i) // 대각선 (좌)
		tri[top.y + i][top.x - i] = true;

	for (int i = 0; top.x + i < right.x; ++i) // 대각선 (우)
		tri[i + top.y][top.x + i] = true;

	for (int i = 0; i < right.x - left.x; ++i)
	{
		int limit = i;
		for(i; i < limit + 5; ++i)
			tri[left.y][left.x + i] = true;
	}

	int newLX = left.x + N / exp2(level);
	int newLY = left.y - (left.y - top.y) / 2 - 1;
	int newRX = right.x - N / exp2(level);
	int newRY = right.y - (right.y - top.y) / 2 - 1;

	PolyTriangle(top, Point(newLX, newLY), Point(newRX, newRY), level + 1); // Top
	PolyTriangle(Point(newLX - 1, left.y - N / exp2(level) + 1), left, Point(top.x - 1, left.y), level + 1); // Left
	PolyTriangle(Point(newRX + 1, right.y - N / exp2(level) + 1), Point(top.x + 1, left.y), right, level + 1); // right
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	std::cin >> N;
	
	maxLevel = log2((N / 3)) + 1; // 프랙탈의 최고 단계 계산

	PolyTriangle(Point(N, 1), Point(1, N), Point(2*N - 1, N), 1);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N * 2 - 1; ++j)
			if (tri[i][j])
				std::cout << '*';
			else
				std::cout << ' ';
		std::cout << '\n';
	}

	return 0;
}
