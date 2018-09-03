#include <iostream>
#include <algorithm>
#include <limits>

int N, K;
int coin[101];
int dp[10001];
int max = std::numeric_limits<int>::max();

int Min(int a, int b)
{
	return a < b ? a : b;
}
 
int main()
{
	std::cin >> N >> K;
	for (int i = 1; i <= 10000; ++i)
		dp[i] = std::numeric_limits<int>::max();
	for (int i = 1; i <= N; ++i)
		std::cin >> coin[i];
	std::sort(coin + 1, coin + N + 1);
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= K; ++j)
			if(j - coin[i] >= 0 && dp[j - coin[i]] != max)
				dp[j] = Min(dp[j - coin[i]] + 1, dp[j]);

	std::cout << (dp[K] == max ? -1 : dp[K]);
	return 0;
}
