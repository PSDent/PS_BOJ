#include <iostream>
#include <cmath>

int N;
int fibo[1000001] = { 0, 1 };

int main()
{
	std::cin >> N;

	for (int i = 2; i <= abs(N); ++i)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000000;

	if (N == 0) std::cout << 0 << '\n';
	else if (N >= 1) std::cout << 1 << '\n';
	else if (N <= -1)
	{
		if (N % 2 == 0) std::cout << -1 << '\n';
		else std::cout << 1 << '\n';
	}
	std::cout << fibo[abs(N)];

	return 0;
}
