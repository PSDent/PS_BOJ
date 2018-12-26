#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 1; j <= N + i; ++j)
			if (j == N - i || j == N + i)
				std::cout << '*';
			else
				std::cout << ' ';
		std::cout << '\n';
	}

	for (int i = 0; i < N * 2 - 1; ++i)
		std::cout << '*';

	return 0;
}
