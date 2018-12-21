#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int limit = N * 2 + 1;
	int sign = -1;
	for (int i = 0; i < N * 2 - 1; ++i)
	{
		if (limit - 2 < 1)
			sign = 1;
		limit += 2 * sign;
		
		for (int j = 0; j < ((N * 2 - 1) - limit) / 2; ++j)
			std::cout << ' ';
		for (int j = 0; j < limit; ++j)
			std::cout << '*';

		std::cout << '\n';
	}

	return 0;
}