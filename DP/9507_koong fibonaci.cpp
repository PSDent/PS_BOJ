#include <iostream>

unsigned long long dp[68] = { 1, 1, 2, 4, 8 };

void koong()
{
	for (int i = 5; i < 68; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];

	return;
}

int main()
{
	int t, koongFibo;;
	koong();

	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> koongFibo;
		std::cout << dp[koongFibo] << std::endl;
	}
	return 0;
}