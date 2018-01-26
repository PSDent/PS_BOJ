#include <iostream>

int dp[100000] = { 1, 3 };

int main()
{
	int N;

	std::cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	std::cout << dp[N];

	return 0;
}
