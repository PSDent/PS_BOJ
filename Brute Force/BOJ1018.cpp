#include <iostream>
#include <algorithm>

char map[51][51];

int main()
{
	int min = 999999999;
	int N, M;
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			std::cin >> map[i][j];

	for (int i = 0; i <= N - 8; ++i)
	{
		for (int m = 0; m <= M - 8; ++m)
		{
			int wfCnt = 0, bfCnt = 0;
			for (int j = 1 + i; j <= 8 + i; ++j)
			{
				for (int k = 1 + m; k <= 8 + m; ++k)
				{
					if ((j + k) % 2 == 0)
					{
						if (map[j][k] == 'B')
							++wfCnt;
						if (map[j][k] == 'W')
							++bfCnt;
					}
					else
					{
						if (map[j][k] == 'B')
							++bfCnt;
						if (map[j][k] == 'W')
							++wfCnt;
					}
				}
			}
			min = std::min(min, std::min(wfCnt, bfCnt));
		}
	}
	std::cout << min;
	return 0;
}
