#include <iostream>

int dp[1001], val[1001];

int main()
{
	int N, max = 0;

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> val[i];

		for (int j = 1; j < i; j++)
			if (val[j] < val[i] && dp[j] > dp[i])
				dp[i] = dp[j];
		dp[i] += val[i];

		if (dp[i] > max)
			max = dp[i];
	}

	std::cout << max;

	return 0;
}
