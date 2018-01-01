//================================================
// Filename : 11726_2xN Tile.cpp
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/11726
//================================================
#include <iostream>

int dp[1001];

int DP(int x)
{
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= x; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	return dp[x];
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << DP(n);

	return 0;
}
