#include <iostream>

long int dp[201][201]; // 자릿수, N의 합 경우 수 

int main()
{
	int N, K;
	std::cin >> N >> K;

	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;

	for (int i = 1; i <= K; i++) 
		for (int j = 0; j <= N; j++) 
			for (int k = 0; k <= j; k++) 
				dp[i][j] += dp[i - 1][j - k] % 1000000000;

	std::cout << dp[K][N] % 1000000000;

	return 0;
}
