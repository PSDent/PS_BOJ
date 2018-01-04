//================================================
// Filename : 11727_2xN Tiling 2
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/11727
//================================================
#include <iostream>

int Tile(int n)
{
	int dp[1001] = { 0, 1, 3 };

	for (int i = 3; i <= n; i++) 
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;

	return dp[n];
}

int main()
{
	int N;

	std::cin >> N;
	std::cout << Tile(N);

	return 0;
}
