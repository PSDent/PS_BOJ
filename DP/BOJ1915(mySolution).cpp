#include <iostream>
#include <cmath>

// 행, 열
int n,m;
int dp[1001][1001];
char map[1001][1001];
int max = 0;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Min(int a, int b)
{
	return a < b ? a : b;
}

void DP()
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 2; j <= m; ++j)
		{
			// 만일 
			// 제일 작은 정사각형을 가지고 (root(크기) + 1) ^ 2  
			if (map[i][j] != 0)
			{
				if (dp[i - 1][j - 1] > 0 && dp[i - 1][j] > 0 && dp[i][j - 1] > 0)
				{
					if (dp[i - 1][j - 1] == dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1])
					{

						dp[i][j] = (sqrt(dp[i][j - 1]) + 1) * (sqrt(dp[i][j - 1]) + 1);
					}
					else
					{
						int temp = Min(dp[i][j - 1], Min(dp[i - 1][j - 1], dp[i - 1][j]));
						dp[i][j] = (sqrt(temp) + 1) * (sqrt(temp) + 1);
					}
				}
				else
					dp[i][j] = 1;
			}
			max = Max(dp[i][j], max);
		}
	}
}

int main()
{
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			std::cin >> map[i][j];
			map[i][j] -= 48;
			if (i == 1 || j == 1)
			{
				dp[i][j] = map[i][j];
				max = Max(max, dp[i][j]);
			}
		}
	}

	DP();
	std::cout << max;

	return 0;
}
