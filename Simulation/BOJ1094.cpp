#include <iostream>

int main()
{
	int X, val = 64;
	int sum = val;
	int cnt = 1;

	std::cin >> X;

	while (sum != X) {
		if (sum - val / 2 >= X) {
			sum -= val / 2;
			val /= 2;
		}
		else {
			val /= 2;
			++cnt;
		}
	}

	std::cout << cnt;

	return 0;
}
