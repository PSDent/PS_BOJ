#include <iostream>

int dp[1000000] = { 1, 1, 2 };

int main()
{
	int N;

	std::cin >> N;

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 2] * 2 + dp[i - 3]) % 15746;

	std::cout << dp[N];

	return 0;
}
