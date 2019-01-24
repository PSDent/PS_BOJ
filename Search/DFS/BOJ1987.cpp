#include <iostream>
#include <algorithm>

int R, C;
char map[21][21];
bool check[26];
int dirX[4] = { 0, 1, 0, -1 }, dirY[4] = { -1, 0, 1, 0 };

int DFS(int x, int y, int step)
{
	int max = 0, index = map[y][x] - 'A';
	if (x < 1 || x > C || y < 1 || y > R || check[index]) return step - 1;

	check[index] = true;

	for (int i = 0; i < 4; ++i)
		max = std::max(max, DFS(x + dirX[i], y + dirY[i], step + 1));
	check[index] = false;
	return max;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> R >> C;
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			std::cin >> map[i][j];

	std::cout << DFS(1, 1, 1);

	return 0;
}
