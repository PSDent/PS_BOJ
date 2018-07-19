#include <iostream>

int N;
long long dp[101][11] = { {}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
long long mod = 1000000000;

long long DP()
{
	long long sum = 0;

	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = dp[i-1][1] % mod;
		for (int j = 1; j <= 9; ++j)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
	}
	for (int i = 0; i <= 9; ++i)
		sum += dp[N][i];

	return sum;
}

int main()
{
	std::cin >> N;
	std::cout << DP() % mod;
	return 0;
}
