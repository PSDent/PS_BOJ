#include <iostream>

using namespace std;
char map[3][101][101];
int dirX[4] = { 0, 1, 0, -1 }, dirY[4] = { -1, 0, 1, 0 };
int cwn = 0, nm = 0;

void ColorWeakness(int x, int y, char pivotColor)
{
	if (map[1][y][x] != pivotColor)
		return;

	map[1][y][x] = 'V';

	for (int i = 0; i < 4; ++i)
		ColorWeakness(x + dirX[i], y + dirY[i], pivotColor);
}

void Normal(int x, int y, char pivotColor)
{
	if (map[2][y][x] != pivotColor)
		return;

	map[2][y][x] = 'V';

	for (int i = 0; i < 4; ++i)
		Normal(x + dirX[i], y + dirY[i], pivotColor);
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[0][i][j];
			map[1][i][j] = map[2][i][j] = map[0][i][j];
			
			if (map[1][i][j] != 'B')
				map[1][i][j] = 'Y';
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[1][i][j] != 'V')
			{
				++cwn; ColorWeakness(j, i, map[1][i][j]);
			}

			if (map[2][i][j] != 'V')
			{
				++nm; Normal(j, i, map[2][i][j]);
			}
		}
	}

	cout << nm << ' ' << cwn;

	return 0;
}
