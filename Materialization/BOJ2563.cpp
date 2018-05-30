#include <iostream>

bool map[101][101];
int count = 0;

void FillMap(int sx, int sy)
{
	for (int i = sy; i < sy + 10; ++i)
	{
		for (int j = sx; j < sx + 10; ++j)
		{
			map[i][j] = true;
		}
	}
}

void CountBlock()
{
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
			if (map[i][j])
				++count;
	}
	std::cout << count;
}

int main()
{
	int n;
	int x, y;
	int max_X = 0, max_Y = 0;

	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> x >> y;
		FillMap(x, y);
	}

	CountBlock();


	return 0;
}
