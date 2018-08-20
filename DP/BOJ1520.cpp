#include <iostream>

int M, N;
int board[501][501];
int dp[501][501];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

int Search(int x, int y)
{
	if (dp[y][x] != -1)
		return dp[y][x];
	if (x == 1 && y == 1)
		return 1;

	dp[y][x] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && nx <= N && ny > 0 && ny <= M)
			if (board[ny][nx] > board[y][x])
				dp[y][x] += Search(nx, ny);
	}

	return dp[y][x];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::cin >> M >> N; // 세로 x 가로 
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			std::cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	dp[1][1] = 1;
	Search(N, M);
	std::cout << dp[M][N];
}
