#include <iostream>

long long dp[1000001] = { 1, 2, 7, 22 };
long long dp2[1000001] = {0, 0, 0, 1};
long long mod = 1000000007;

int main()
{
	int N;
	std::cin >> N;

	for (int i = 4; i <= N; ++i)
	{
		dp2[i] = dp2[i - 1] + dp[i - 3];
		dp[i] = ((dp[i - 1] * 2) + (dp[i - 2] * 3) + dp2[i] * 2) % mod;
	}
	std::cout << dp[N];

	return 0;
}
