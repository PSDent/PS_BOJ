#include <iostream>

int bamboo[502][502];
long long int dp[502][502];
int max = 0, n;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int calDays(int x, int y, int days)
{
	if (dp[y][x] == 1)
		return 2;
	else if (dp[y][x] > 1)
		return dp[y][x] + 1;

	int cnt = 1;

	if (x > 1 && bamboo[y][x - 1] > bamboo[y][x])
		cnt = Max(cnt, calDays(x - 1, y, days + 1));
	if (x < n && bamboo[y][x + 1] > bamboo[y][x])
		cnt = Max(cnt, calDays(x + 1, y, days + 1));
	if (y > 1 && bamboo[y - 1][x] > bamboo[y][x])
		cnt = Max(cnt, calDays(x, y - 1, days + 1));
	if (y < n && bamboo[y + 1][x] > bamboo[y][x])
		cnt = Max(cnt, calDays(x, y + 1, days + 1));

	dp[y][x] = cnt;

	return cnt + 1;
}

int main()
{
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = -1;
			std::cin >> bamboo[i][j];
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == -1)
				calDays(j, i, 1);
			max = Max(max, dp[i][j]);
		}
	std::cout << max;

	return 0;
}
