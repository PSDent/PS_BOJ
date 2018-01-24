#include <iostream>

int dp[2][1001], var[1001];

int main()
{
	int N, max = 0;
	std::cin >> N;

	for (int i = 1; i <= N; i++) 
		std::cin >> var[i];

	for (int i = 1; i <= N; i++) { // L -> R
		for (int j = 1; j < i; j++) {
			if (var[i] > var[j] && dp[0][i] < dp[0][j])
				dp[0][i] = dp[0][j];
		}
		dp[0][i] += 1;
	}
	for (int i = N; i >= 1; i--) { // R -> L
		for (int j = N; j > i; j--) {
			if (var[i] > var[j] && dp[1][i] < dp[1][j])
				dp[1][i] = dp[1][j];
		}
		dp[1][i] += 1;
	}

	for (int i = 1; i <= N; i++) 
		if (max < dp[1][i] + dp[0][i])
			max = dp[1][i] + dp[0][i];

	std::cout << max - 1;

	return 0;
}
