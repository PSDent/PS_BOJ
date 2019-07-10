#include <iostream>
#include <algorithm>

int w[101], v[101];
int dp[101][100001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, K, max = 0;
	std::cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		std::cin >> w[i] >> v[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (w[i] <= j)
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			max = std::max(dp[i][j], max);
		}
	}

	std::cout << max;

	return 0;
}
