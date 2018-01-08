//================================================
// Filename : 2133_Fill Tile
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2133
//================================================
#include <iostream>

long dp[31] = { 1, 0, 3};

long Tile(int x) {
	for (int i = 4; i <= x; i += 2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2)
			dp[i] += dp[i - j] * 2;
	}
	return dp[x];
}

int main()
{
	int n;

	std::cin >> n;
	std::cout << Tile(n);

	return 0;
}
