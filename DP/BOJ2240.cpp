#include <iostream>

int T, W;	
bool plum[1001][3];
int dp[1002][32][3];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int input, max = 0;
	std::cin >> T >> W;
	for (int i = 1; i <= T; ++i)
	{
		std::cin >> input;
		plum[i][input] = true;
	}

	dp[1][0][1] = plum[1][1];
	dp[1][1][2] = plum[1][2];
	for (int i = 2; i <= T; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			dp[i][j][1] = Max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + plum[i][1];
			dp[i][j][2] = Max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + plum[i][2];
			max = Max(max, dp[i][j][1]);
			max = Max(max, dp[i][j][2]);
		}
	}
	std::cout << max;
	return 0;
}