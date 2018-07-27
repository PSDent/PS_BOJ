#include <iostream>

int N;
int arr[100000];
int dp[100001];
int max = 0;

int Max(int a, int b)
{
	return a > b ? a : b;
}

void SeriesSum()
{
	max = arr[0];
	if (N == 1) return;

	dp[0] = arr[0];
	for (int i = 1; i < N; ++i)
	{
		dp[i] = Max(dp[i - 1] + arr[i], arr[i]);
		max = Max(max, dp[i]);
	}
}

int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
	SeriesSum();

	std::cout << max;

	return 0;
}
