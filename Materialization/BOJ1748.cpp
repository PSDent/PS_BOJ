#include <iostream>

int main()
{
	int N, weight = 1, mul = 10;
	int sum = 0;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		if (i == mul)
		{
			mul *= 10;
			++weight;
		}
		sum += weight;
	}
	std::cout << sum;
}
