#include <iostream>

bool x[51], y[51];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	int xCnt = 0, yCnt = 0;

	std::cin >> N >> M;

	char input;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			std::cin >> input;
			if (input == 'X')
			{
				if (!x[j])
					++xCnt;
				if (!y[i])
					++yCnt;
				x[j] = true;
				y[i] = true;
				
			}
		}
	}

	int max = (N - yCnt > M - xCnt) ? (N - yCnt) : (M - xCnt);
	std::cout << max;

	return 0;
}
