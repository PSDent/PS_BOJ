//================================================
// Filename : 1149_RGB Street
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1149
//================================================
#include <iostream>

int price[1001][4];
int dp[1001][4] = { 0, 0, 0, 0 };

int Min(int a, int b) { return a < b ? a : b; }

int main()
{
	int  N;

	std::cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		std::cin >> price[i][1] >> price[i][2] >> price[i][3];
	}


	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = Min(dp[i-1][2], dp[i-1][3]) + price[i][1];
		dp[i][2] = Min(dp[i-1][1], dp[i-1][3]) + price[i][2];
		dp[i][3] = Min(dp[i-1][1], dp[i-1][2]) + price[i][3];
	}

	std::cout << Min(Min(dp[N][1], dp[N][2]), dp[N][3]);

	return 0;
}
