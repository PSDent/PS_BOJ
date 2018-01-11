//================================================
// Filename : 2167_Sum_of_2D_Array.cpp
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2167
//================================================
#include <iostream>

int dp[301][301];

int Dp(int i, int j, int x, int y) {
	return dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1];
}

int main()
{
	int N, M, K;

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) {
			std::cin >> dp[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + dp[i][j];
		}

	std::cin >> K;

	for (int l = 0; l < K; l++) {
		int i, j, x, y;
		
		std::cin >> i >> j >> x >> y;
		std::cout << Dp(i, j, x, y) << std::endl;
	}

	return 0;
}