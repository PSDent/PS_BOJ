#include <iostream>

int bamboo[502][502];
long long int dp[502][502];
int max = 0, n;

void calDays(int x, int y)
{
	if (max < dp[y][x])
		max = dp[y][x];

	if (bamboo[y][x - 1] > bamboo[y][x] && dp[y][x] >= dp[y][x - 1]) {
		dp[y][x - 1] = dp[y][x] + 1;
		calDays(x - 1, y);
	}

	if (bamboo[y][x + 1] > bamboo[y][x] && dp[y][x] >= dp[y][x + 1]) {
		dp[y][x + 1] = dp[y][x] + 1;
		calDays(x + 1, y);
	}

	if (bamboo[y - 1][x] > bamboo[y][x] && dp[y][x] >= dp[y - 1][x]) {
		dp[y - 1][x] = dp[y][x] + 1;
		calDays(x, y - 1);
	}

	if (bamboo[y + 1][x] > bamboo[y][x] && dp[y][x] >= dp[y + 1][x]) {
		dp[y + 1][x] = dp[y][x] + 1;
		calDays(x, y + 1);
	}

	return;
}

int main()
{
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> bamboo[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			calDays(j, i);

	std::cout << max + 1;

	return 0;
}
