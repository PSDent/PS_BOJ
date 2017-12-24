//================================================
// Filename : 2156_Eat Wine
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2156
//================================================
#include <iostream>
#include <cmath>

int wine[10001] = { 0 };
int dp[10001] = { 0 };
int n;

int MaxVal(int a, int b, int c) {
	int x = a > b ? a : b;
	return x > c ? x : c;
}

void maxWine()
{
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	for (int i = 3; i <= n; i++) 
		dp[i] = MaxVal(dp[i-1], wine[i] + dp[i-2], wine[i] + wine[i-1] + dp[i-3]);

	return;
}

int main()
{
	std::cin >> n;

	for (int i = 1; i <= n; i++) 
		std::cin >> wine[i];

	maxWine();
	std::cout << dp[n];

	return 0;
}