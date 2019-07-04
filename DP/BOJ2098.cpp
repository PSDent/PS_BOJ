#include <iostream>
#include <algorithm>
#include <cstring>

int w[16][16];
int dp[1 << 16][16];		// 방문상태에서 남은 노드를 방문하는 최소비용
const int MAX = 0x3f3f3f3f;
int N;

int TSP(int current, int now)
{
	// 모두 방문한 상태는 (1 << n) - 1
	if (current == (1 << N) - 1)
		if (w[now][0])
			return w[now][0];
		else
			return MAX;

	int &ret = dp[current][now];
	if (ret != MAX) return ret;

	for (int i = 0; i < N; ++i) // 방문 안한 도시 탐색
	{
		if (current &(1 << i) || !w[now][i]) continue;
		ret = std::min(ret, TSP(current | (1 << i), i) + w[now][i]);
	}

	return ret;
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			std::cin >> w[i][j];

	memset(dp, MAX, sizeof(dp));
	std::cout << TSP(1, 0);

	return 0;
}
