#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N * 2 - 1; ++i)
	{
		int limit = abs(N - abs(N - i));

		for (int j = 1; j <= limit; ++j)
			std::cout << '*';
		for (int j = 1; j <= N * 2 - limit * 2; ++j)
			std::cout << ' ';
		for (int j = 1; j <= limit; ++j)
			std::cout << '*';
		std::cout << '\n';
	}

	return 0;
}