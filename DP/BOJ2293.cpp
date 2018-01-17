#include <iostream>

int dp[10001] = { 1 }, cn[101];

int main()
{
	int n, k;

	std::cin >> n >> k;

	for (int i = 1; i <= n; i++)
		std::cin >> cn[i];

	for (int i = 1; i <= n; i++) 
		for (int j = cn[i]; j <= k; j++) 
			dp[j] += dp[j - cn[i]];

	std::cout << dp[k];

	return 0;
}
