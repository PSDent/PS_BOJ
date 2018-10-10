#include <iostream>
#include <ios>

int N, M;
int arr[2001];
bool dp[2001][2001];

void Pal()
{
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j < i; ++j)
			if ( (dp[j + 1][i - 1] || i - j == 1) && arr[j] == arr[i])
				dp[j][i] = dp[i][j] = 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int S, E;
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		dp[i][i] = true;
		std::cin >> arr[i];
	}

	Pal();

	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> S >> E;
		std::cout << dp[S][E] << '\n';
	}

	return 0;
}
