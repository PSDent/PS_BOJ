#include <iostream> 

int coin[21];      // 동전의 종류가 저장 됨
int N, M;          // 각각 동전 수, 목표 금액 
int dp[21][10001]; // 금액 i에 대한 경우의 수

int Coin()
{
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		std::cin >> coin[i];
		dp[i][0] = 1;
	}
	std::cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j - coin[i] >= 0)
				dp[i][j] += dp[i][j - coin[i]];
		}
	}

	return dp[N][M];
}

int main()
{
	int T;

	std::cin >> T;
	for (int i = 0; i < T; i++)
		std::cout << Coin() << std::endl;

	return 0;
}