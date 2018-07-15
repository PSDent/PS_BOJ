#include <iostream>

using namespace std;

int T;
int dp[101][101][2];

void DP()
{
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i <= 100; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp[i][j][0] = dp[i-1][j][0] + dp[i -1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + (j > 0 ? dp[i - 1][j - 1][1] : 0);
		}
	}

	return;
}

int main()
{
	int n, k;

	cin >> T;

	DP();
	for (int i = 0; i < T; ++i)
	{
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << '\n';
	}

	return 0;
}
