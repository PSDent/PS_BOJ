//================================================
// Filename : 11048_Move.cpp
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/11048
//================================================
#include <iostream>

int dp[1000][1000] = { 0 };
int maze[1000][1000];
int N, M;

int MaxComp(int a, int b, int c){
	int temp = a > b? a : b;
    return temp > c ? temp : c;
}

void CalMaxCandy()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j > 0 && i > 0) dp[i][j] = MaxComp(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + maze[i][j];
			else if (i == 0 && j > 0) dp[i][j] = dp[i][j - 1] + maze[i][j];
			else if (j == 0 && i > 0) dp[i][j] = dp[i - 1][j] + maze[i][j];
		}
	}

	return;
}

int main()
{
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			std::cin >> maze[i][j];
			dp[i][j] = maze[i][j];
		}

	CalMaxCandy();
	std::cout << dp[N-1][M-1];

	return 0;
}
