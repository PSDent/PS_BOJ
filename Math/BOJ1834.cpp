#include <iostream>

int main()
{
	long long N, num, sum = 0, mul = 2;
	std::cin >> N;
	num = N + 1;

	while (num / N == num % N)
	{
		sum += num;
		num = (N + 1) * mul;
		++mul;
	}
	std::cout << sum;

	return 0;
}
