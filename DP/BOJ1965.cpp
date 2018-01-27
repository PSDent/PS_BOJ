#include <iostream>

int dp[1001], arr[1001];

int main()
{
	int N, max = 0;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
		std::cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j])
				dp[i] = dp[j];
		}
		dp[i] += 1;
		if (max < dp[i])
			max = dp[i];
	}

	std::cout << max;

	return 0;
}
