#include <iostream>
#include <cmath>

int dp[100001] = { 0, 1 };

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1)
				dp[i] = dp[i - j * j] + 1;
		}
	}

	std::cout << dp[N];
	return 0;
}
