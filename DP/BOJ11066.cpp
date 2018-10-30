#include <iostream>
#include <algorithm>

const int INF = 0x7fffffff/2;
int dp[501][501], arr[501], sum[501];

int Merge(int start, int end)
{
	if (start >= end) return 0;
	if (dp[start][end] != -1) return dp[start][end];
	if (start + 1 == end) return arr[start] + arr[end];

	dp[start][end] = INF;

	for (int i = start; i <= end; ++i)
	{
		int val = Merge(start, i) + Merge(i + 1, end) + sum[end] - sum[start - 1];
		dp[start][end] = std::min(dp[start][end], val);
	}

	return dp[start][end];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T, K;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		std::cin >> K;
		for (int j = 1; j <= K; ++j)
		{
			std::cin >> arr[j];
			sum[j] = sum[j-1] + arr[j];
		}

		for(int j = 1; j <= K; ++j)
			for (int k = 1; k <= K; ++k) dp[j][k] = -1;
		std::cout << Merge(1, K) << '\n';
	}
	return 0;
}
