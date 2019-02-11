#include <iostream>

int main()
{
	int N, K;
	std::cin >> N;
	for(int i = 2; i * i <= N; ++i)
		if (N % i == 0)
		{
			K = N / i;
			break;
		}

	std::cout << N - K;

	return 0;
}
