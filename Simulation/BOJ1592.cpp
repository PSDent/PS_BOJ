#include <iostream>

int cnt[1001];

int main()
{
	int N, M, L, throwCnt = 0, now = 0;
	std::cin >> N >> M >> L;

	while (true)
	{
		++cnt[now];
		if (cnt[now] == M)
			break;
		++throwCnt;

		if (cnt[now] % 2 == 1)
			now = (now + L) % N;
		else
			now = (now - L + N) % N;
	}
	std::cout << throwCnt;

	return 0;
}
