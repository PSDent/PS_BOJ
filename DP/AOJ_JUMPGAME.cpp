#include <iostream>

int N;
int grid[101][101];
bool cache[101][101];
char *str[2] = { "NO", "YES" };

void Search(int x, int y)
{
	if (x == N && y == N) {
		cache[N][N] = true;
		return;
	}

	if (!cache[N][N]) {
		if (x + grid[y][x] <= N && !cache[y][x + grid[y][x]])
			Search(x + grid[y][x], y);
		else
			cache[y][x] = true;

		if (y + grid[y][x] <= N && !cache[y + grid[y][x]][x])
			Search(x, y + grid[y][x]);
		else
			cache[y][x] = true;
	}

	return;
}

int main()
{
	int testCase;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		std::cin >> N;

		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++) {
				cache[j][k] = false;
				std::cin >> grid[j][k];
			}

		Search(1, 1);
		std::cout << str[cache[N][N]] << '\n';
	}

	return 0;
}