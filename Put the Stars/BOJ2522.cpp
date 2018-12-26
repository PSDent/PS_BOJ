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
		int mid = abs(i - N);

		for (int j = 0; j < mid; ++j)
			std::cout << ' ';
		for (int j = mid; j < N; ++j)
			std::cout << '*';
		std::cout << '\n';
	}

	return 0;
}
