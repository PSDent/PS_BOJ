//================================================
// Filename : 9005_1, 2, 3 add
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/9095
//================================================
#include <iostream>

int dp[12] = {0, 1, 2, 4, };

void DP()
{
	for (int i = 4; i <= 12; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	return;
}

int main()
{
	DP();
	int T;

	std::cin >> T;

	int temp;
	for (int i = 1; i <= T; i++)
	{
		std::cin >> temp;
		std::cout << dp[temp] << std::endl;
	}

	return 0;
}
