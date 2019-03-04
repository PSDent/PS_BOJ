#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	int N, a, b, now, max;
	
	std::cin >> N >> now;
	max = now;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		now += a - b;

		if (now < 0)
		{
			std::cout << 0;
			return 0;
		}

		max = std::max(now, max);
	}
	std::cout << max;

	return 0;
}
