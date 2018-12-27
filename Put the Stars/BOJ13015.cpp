#include <iostream>
#include <cmath>

bool star[201][600];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N * 4 - 3; ++i)
	{
		if (i <= N || i > N + N * 2 - 3)
			star[1][i] = star[N * 2 - 1][i] = true;
	}

	// 빈 공간 = N - 2 
	for (int i = 2; i <= N * 2 - 2; ++i)
	{
		int empty = N - 2 + 1;
		int midEmpty = (N * 2 - 3) - ((N - abs(N - i) - 1) * 2) + 1;
		if (midEmpty < 0)
			midEmpty = 0;
		int startPos = N - abs(N - i);

		star[i][startPos] = star[i][startPos + empty] = true;
		star[i][startPos + empty + midEmpty] = star[i][startPos + midEmpty + empty * 2] = true;
	}

	for (int i = 1; i <= N * 2 - 1; ++i)
	{
		for (int j = 1; j <= N * 4 - 3 - (N - abs(N - i)) + 1; ++j)
		{
			if (star[i][j])
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
