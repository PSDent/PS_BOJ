#include <iostream>

long long dp[101] = { 0, 1, 1, 1, 2 };

void Padovan(int val)
{
	if (dp[val] != 0)
		return;

	for (int i = 5; i <= val; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	return;
}

int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;
		Padovan(input);

		std::cout << dp[input] << '\n';
	}

	return 0;
}
