#include <iostream>

long long dp[65][11] = { {}, { 1,1,1,1,1,1,1,1,1,1,10 }};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	
	for (int i = 2; i <= 64; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = j; k < 10; ++k)
			{
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][10] += dp[i][j];
		}
	}

	for (int i = 0; i < T; ++i)
	{
		int input;
		std::cin >> input;
		std::cout << dp[input][10] << '\n';
	}

	return 0;
}
