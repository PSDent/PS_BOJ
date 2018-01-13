//================================================
// Filename : 1010_Build Bridget.cpp
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1010
//================================================
#include <iostream>

int dp[31][31];

void DP()
{
	dp[0][0] = 1;

	for (int i = 1; i <= 30; i++)
		for (int j = i; j <= 30; j++) {
			if (i != 1)
				for (int k = j-1; k >= 1; k--)
					dp[i][j] += dp[i - 1][k];
			else 
				dp[i][j] = j;
		}
}

int main()
{
	int T, N, M;

	std::cin >> T;

	DP();

	for (int i = 0; i < T; i++) {
		std::cin >> N >> M;
		std::cout << dp[N][M] << std::endl;
	}


	return 0;
}