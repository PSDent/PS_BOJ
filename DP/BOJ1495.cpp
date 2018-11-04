#include <iostream>

bool dp[101][1001];
int volume[101];
int N, S, M;

int main()
{
	std::cin >> N >> S >> M;

	for (int i = 1; i <= N; ++i)
		std::cin >> volume[i];

	dp[0][S] = true;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			if (dp[i - 1][j])
			{
				if (j + volume[i] <= M)
					dp[i][j + volume[i]] = true;
				if (j - volume[i] >= 0)
					dp[i][j - volume[i]] = true;
			}
		}
	}

	for (int i = M; i >= 0; --i)
		if (dp[N][i])
		{
			std::cout << i;
			return 0;
		}
	std::cout << -1;

	return 0;
}
