#include <iostream>

int main()
{
	int N, sum = 0;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
		sum += (i + 1) * (i + i * 2) / 2;
	std::cout << sum;

	return 0;
}
