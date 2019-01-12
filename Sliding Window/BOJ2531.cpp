#include <iostream>
#include <algorithm>

int sushiNum[3001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int sushi[33000];
	int N, D, K, C;
	std::cin >> N >> D >> K >> C;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> sushi[i];
		if(i + N < N + K) sushi[i + N] = sushi[i];
	}

	int cnt = 0;
	++sushiNum[C]; ++cnt;

	for (int i = 0; i < K; ++i)
	{
		if (!sushiNum[sushi[i]]) ++cnt;
		++sushiNum[sushi[i]];
	}

	int max = 0;
	for (int i = K; i < N + K; ++i)
	{
		--sushiNum[sushi[i - K]];
		if (!sushiNum[sushi[i - K]]) --cnt;
		if (sushiNum[sushi[i]] == 0) ++cnt;
		++sushiNum[sushi[i]];

		max = std::max(max, cnt);
	}

	std::cout << max;

	return 0;
}