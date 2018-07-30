#include <iostream>

int main()
{
	int N, cnt = 0;
	std::cin >> N;

	for (int i = 1; i <= static_cast<float>(N) / 2 + 0.5f; ++i)
	{
		for (int j = i; i * j <= N; ++j)
			++cnt;
	}
	std::cout << cnt;
	return 0;
}
