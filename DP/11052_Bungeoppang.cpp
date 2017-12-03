//================================================
// Filename : 11052_Bungeoppang
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/11052
//================================================
#include <iostream>

int dp[1001], set[1001], N;

int maxComp(int a, int b) {
	return a > b ? a : b;
}

void DP() {
	dp[1] = set[1];
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = maxComp(dp[i], dp[i - j] + set[j]);
}

int main() {
	std::cin >> N; 
	for (int i = 1; i <= N; i++) std::cin >> set[i];
	
	DP();
	std::cout << dp[N];
	return 0;
}
