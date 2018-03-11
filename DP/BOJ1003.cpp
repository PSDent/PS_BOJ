#include <iostream>

int dp[41][2] = { {1, 0}, {0, 1}};
bool cache[41];

void fibonacci() {
	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
}

int main()
{
	int T, N;
	std::cin >> T;

	fibonacci();

	for (int i = 0; i < T; i++) {
		std::cin >> N;
		std::cout << dp[N][0] << ' ' << dp[N][1] << '\n';
	}

	return 0;
}
