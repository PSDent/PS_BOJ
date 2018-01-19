#include <iostream>

int dp[1001][11] = { {1,1,1,1,1,1,1,1,1,1,10}, };

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i - 1][10];
		int sum = dp[i][0];

		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1] + 10007) % 10007;
			sum += dp[i][j];
		}
		dp[i][10] = sum % 10007;
	}

	std::cout << dp[N-1][10];

	return 0;
}
