#include <iostream>
#include <cmath>

int main()
{
	long long N, L;
	std::cin >> N >> L;

	while (L <= 100)
	{
		for (int i = N / L + L; i >= 0; --i)
		{
			if (i - (L - 1) < 0) break;
			long long num = (L * (i + i - (L - 1))) / 2;
			if (num == N)
			{
				for (int j = i - (L - 1); j <= i; ++j)
					std::cout << j << ' ';
				return 0;
			}
			else if (num < N) break;
		}
		++L;
	}

	std::cout << -1;

	return 0;
}
