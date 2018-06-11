#include <iostream>

int dp[46] = { 0,1 };

int main()
{
	int n;
	std::cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[n];

	return 0;
}
