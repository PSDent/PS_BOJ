#include <iostream>

int dp[41], vip[41]; 

int main()
{
	int N, M, index = 1;
	dp[0] = dp[1] = 1;

	std::cin >> N >> M;        // VIP slot
	for (int i = 1; i <= M; i++)
		std::cin >> vip[i];

	for (int i = 2; i <= N; i++) {
		if (i == vip[index]) {
			dp[i] = dp[i - 1];
		}
		else if (i == vip[index] + 1) {
			dp[i] = dp[i - 1];
			index++;
		}
		else
			dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[N];

	return 0;
}
