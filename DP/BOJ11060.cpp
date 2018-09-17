#include <iostream>

int jump[1001];
int dp[1001];
int N, min = 1001;

int Min(int a, int b){ return a < b ? a : b; }

int Jump(int index, int cnt)       
{
	if (cnt > min) return 1001;

	if (index == N && cnt <= min)
	{
		min = Min(min, cnt);
		dp[index] = 0;
		return 0;
	}

	if (dp[index] != 1001) return dp[index];

	for (int i = index + 1; i <= index + jump[index]; ++i)
		dp[index] = Min(dp[index], Jump(i, cnt + 1) + 1);
	return dp[index];
}

int main()
{
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		dp[i] = 1001;
		std::cin >> jump[i];
	}

	Jump(1, 0);
	
	if (dp[1] == 1001) std::cout << -1;
	else std::cout << dp[1];

	return 0;
}
