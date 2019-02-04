#include <iostream>

int main()
{
	int N, mul = 1;
	std::cin >> N;

	while (N > (mul *= 10))
	{
		int pMul = mul / 10;
		int origin = (N % mul) / pMul;
		int now = ((N + 5 * pMul) % mul) / pMul;
		if (now < origin)
			N = N + (10 - origin) * pMul;
		else
			N = N - (origin * pMul);
	}
	std::cout << N;

	return 0;
}
