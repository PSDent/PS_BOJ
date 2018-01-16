#include <iostream>

int dp[2][100001];

int Max(int a, int b) {
	return a > b ? a : b;
}

int DP(int n) {
	for (int j = 2; j <= n; j++) {
		dp[0][j] = Max(dp[1][j - 1], dp[1][j - 2]) + dp[0][j];
		dp[1][j] = Max(dp[0][j - 1], dp[0][j - 2]) + dp[1][j];
	}
	return Max(dp[0][n], dp[1][n]);
}

int main()
{
	int T, N;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> N;
		for (int j = 1; j <= N; j++)
			std::cin >> dp[0][j];
		for (int j = 1; j <= N; j++)
			std::cin >> dp[1][j];

		std::cout << DP(N) << std::endl;
	}

	return 0;
}
