#include <iostream>

int dp[1001], num[1001];

int main()
{
	int n, max = 0;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmpMax = 0;
		std::cin >> num[i];

		for (int j = 1; j < i; j++) {
			if (num[j] < num[i])
				if (dp[j] > tmpMax) 
					tmpMax = dp[j];
		}
		dp[i] = tmpMax + 1;
		if (dp[i] > max)
			max = dp[i];
	}

	std::cout << max;

	return 0;
}
