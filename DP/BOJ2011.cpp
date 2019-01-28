#include <iostream>
#include <string>

const long long MOD = 1000000;
long long dp[5001] = { 1, 1 };
std::string code;

int main()
{
	std::cin >> code;

	if (code[0] == '0')
	{
		std::cout << 0;
		return 0;
	}

	for (int i = 2; i <= code.size(); ++i)
	{
		int num = (code[i - 2] - '0') * 10 + code[i - 1] - '0';

		if (num < 10 || num > 26)
			dp[i] = dp[i - 1];
		else if (num == 10 || num == 20)
			dp[i] = dp[i - 2];
		else if (num > 10 && num < 27)
			dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}

	std::cout << dp[code.size()];

	return 0;
}
