#include <iostream>
#include <string>

int dp[1001][1001];

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int m = 0;
	std::string str[2];

	for (int i = 0; i < 2; i++) 
		std::cin >> str[i];

	for (int i = 1; i <= str[0].length(); i++) {
		for (int j = 1; j <= str[1].length(); j++) {
			if (str[0][i-1] == str[1][j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	std::cout << dp[str[0].length()][str[1].length()];

	return 0;
}
