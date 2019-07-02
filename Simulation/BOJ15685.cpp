#include <iostream>
#include <iterator>
#include <vector>

bool board[101][101];

int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	while (N--)
	{
		int x, y, d, g, nowGen = 1;
		std::cin >> x >> y >> d >> g;

		std::vector<int> dragonCurve;
		int nx = dirX[d], ny = dirY[d];

		dragonCurve.push_back(d);
		board[y][x] = true;
		x += nx, y += ny;
		board[y][x] = true;

		while (nowGen <= g)
		{
			for (int i = dragonCurve.size() - 1; i >= 0; --i)
			{
				int nd = (dragonCurve[i] + 1) > 3 ? 0 : (dragonCurve[i] + 1);
				int nx = dirX[nd], ny = dirY[nd];

				dragonCurve.push_back(nd);
				x += nx, y += ny;
				board[y][x] = true;
			}

			++nowGen;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
				++cnt;
		}
	}

	std::cout << cnt;

	return 0;
}
