#include <iostream>

bool map[51][51], visit[51][51];
int dirX[4] = { 0, 1, 0, -1 }, dirY[4] = { -1, 0, 1, 0 };
int N, M;
int r, c, d, cnt = 1;

int main()
{
	std::cin >> N >> M;
	std::cin >> r >> c >> d;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			std::cin >> map[i][j];
	}

	int dirCnt = 0;
	visit[r][c] = true;
	while (true)
	{
		if (dirCnt == 4)
		{
			dirCnt = 0;
			int tD = d - 2;
			if (tD < 0)
				tD = 4 + tD;

			int tR = r + dirY[tD];
			int tC = c + dirX[tD];

			if (map[tR][tC])
			{
				std::cout << cnt;
				return 0;
			}
			else
			{
				r = tR;
				c = tC;
			}
		}

		--d;
		if (d < 0) d = 3; 
		int R = r + dirY[d];
		int C = c + dirX[d]; 

		if (!map[R][C] && !visit[R][C])
		{
			dirCnt = 0;
			visit[R][C] = true;
			r = R, c = C;
			++cnt;
		}
		else if (visit[R][C] || map[R][C] || (R < 0 || R > N - 1 || C < 0 || C > M - 1))
		{
			++dirCnt;
		}
	}

	return 0;
}
