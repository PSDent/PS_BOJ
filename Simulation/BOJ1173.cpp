#include <iostream>

int main()
{
	int N, m, M, T, R, minute = 0, now;
	std::cin >> N >> m >> M >> T >> R;
	now = m;

	if (m + T > M) {
		std::cout << -1;
		return 0;
	}
	while (N > 0)
	{
		if ( (M - now) / T)
		{
			N -= (M - now) / T;
			minute += (M - now) / T;
			if (N < 0)
				minute += N;
			now += ((M - now) / T) * T;
		}
		else
		{
			now -= R;
			if (now < m)
				now = m;
			++minute;
		}
	}

	std::cout << minute;

	return 0;
}
