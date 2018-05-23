#include <iostream>
#include <cmath>

int main()
{
	int M, N, val, min = 0, sum = 0;

	std::cin >> M >> N;

	val = sqrt(M);

	if (val * val != M)
		val++;

	min = val * val;

	for (int i = val; i * i <= N; ++i)
	{
		sum += i * i;
	}

	if (sum == 0)
		std::cout << "-1";
	else
	{
		std::cout << sum << '\n';
		std::cout << min;
	}

	return 0;
} 
