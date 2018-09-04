#include <iostream>

int dp[1001][1001];
int N, K;
int mod = 10007;

int main()
{
	std::cin >> N >> K;

	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; ++j)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	std::cout << dp[N][K];

	return 0;
}

