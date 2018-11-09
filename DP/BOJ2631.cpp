#include <iostream>

int arr[201], dp[201], max = 0;

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
		if (dp[i] > max)
			max = dp[i];
	}

	std::cout << N - max;

	return 0;
}
