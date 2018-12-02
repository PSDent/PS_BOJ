#include <iostream>
#include <algorithm>
#include <limits>

int N, M;
int map[1005][1005];
int dp[3][1005][1005]; // 0 = ans, 1 = L, U , 2 = R, U

int main()
{
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			std::cin >> map[i][j];
			if (i == 1)
				dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[0][i][j - 1] + map[i][j];
			else
				dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = std::numeric_limits<int>::min();
		}

	for (int i = 2; i <= N; ++i)
	{
		dp[1][i][1] = dp[0][i - 1][1] + map[i][1];
		for (int j = 2; j <= M; ++j) // L, U
			dp[1][i][j] = std::max(dp[0][i - 1][j], dp[1][i][j - 1]) + map[i][j];

		dp[2][i][M] = dp[0][i - 1][M] + map[i][M];
		for (int j = M-1; j >= 1; --j) // R, U
			dp[2][i][j] = std::max(dp[0][i - 1][j], dp[2][i][j + 1]) + map[i][j];

		for (int j = 1; j <= M; ++j)
			dp[0][i][j] = std::max(dp[1][i][j], dp[2][i][j]);
	}

	std::cout << dp[0][N][M];

	return 0;
}
