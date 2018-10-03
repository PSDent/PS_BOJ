#include <iostream>

int dp[2][16][16];

int main()
{
	int N, M, K;
	std::cin >> N >> M >> K;

	dp[0][1][1] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			dp[0][i][j] += dp[0][i - 1][j] + dp[0][i][j - 1];

	int pos, row, column;
	if (K > 0)
	{
		pos = K % M == 0 ? 0 : 1;
		row = K / M + pos;
		column = K % M == 0 ? K / row : K % M;

		dp[1][row][column] = 1;
		for (int i = row; i <= N; ++i)
			for (int j = column; j <= M; ++j)
				dp[1][i][j] += dp[1][i - 1][j] + dp[1][i][j - 1];

		std::cout << dp[0][row][column] * dp[1][N][M];
	}
	else
		std::cout << dp[0][N][M];
	
	return 0;
}
