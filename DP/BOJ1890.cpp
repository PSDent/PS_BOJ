#include <iostream>

int board[101][101];
unsigned long dp[101][101];
int N;

int main()
{
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			std::cin >> board[i][j];

	dp[board[1][1] + 1][1] = 1;
	dp[1][board[1][1] + 1] = 1;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (board[i][j] == 0) continue;

			if (board[i][j] + i <= N)
				dp[board[i][j] + i][j] += dp[i][j];
			if (board[i][j] + j <= N)
				dp[i][board[i][j] + j] += dp[i][j];
		}
	}
	std::cout << dp[N][N];
	return 0;
}
