#include <iostream>

int main()
{
	long long x, y, z;
	while (std::cin >> x >> y)
	{
		z = y * 100 / x;
		if (z >= 99) std::cout << -1;
		else
		{
			int start = 1, end = 1000000001, mid;
			while (end >= start)
			{
				mid = (start + end) / 2;
				int val = ((y + mid) * 100) / (x + mid);
				
				if (val > z)
					end = mid - 1;
				else
					start = mid + 1;
			}
			std::cout << start;
		}
	}
	return 0;
}
