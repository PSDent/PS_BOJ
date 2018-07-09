#include <iostream>

int sea[50][50];
int w, h;

void DFS(int x, int y)
{
	sea[y][x] = -1;

	if (x < w - 1 && sea[y][x + 1] == 1) // E
		DFS(x + 1, y);
	if (x < w - 1 && y < h - 1 && sea[y + 1][x + 1] == 1) // SE
		DFS(x + 1, y + 1);
	if (y < h - 1 && sea[y + 1][x] == 1) // S
		DFS(x, y + 1);
	if (x > 0 && y < h - 1 && sea[y + 1][x - 1] == 1) // SW
		DFS(x - 1, y + 1);
	if (x > 0 && sea[y][x - 1] == 1) // W
		DFS(x - 1, y);
	if (x > 0 && y > 0 && sea[y - 1][x - 1] == 1) // NW
		DFS(x - 1, y - 1);
	if (y > 0 && sea[y - 1][x] == 1) // N
		DFS(x, y - 1);
	if (x < w - 1 && y > 0 && sea[y - 1][x + 1] == 1) // NE
		DFS(x + 1, y - 1);
}

int main()
{	
	while(1)
	{
		int amount = 0;

		std::cin >> w >> h;
		if (w == 0)
			return 0;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				std::cin >> sea[i][j];

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
			{
				if (sea[i][j] == 1)
				{
					++amount;
					DFS(j, i);
				}
			}

		std::cout << amount << '\n';
	}

	return 0;
}