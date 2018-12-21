#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j <= N - i; ++j)
			std::cout << ' ';
		for (int j = 1; j <= i * 2 - 1; ++j)
			std::cout << '*';
		std::cout << '\n';
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
			std::cout << ' ';
		for (int j = 1; j <= (N - i + 1) * 2 - 1; ++j)
			std::cout << '*';
		std::cout << '\n';
	}

	return 0;
}