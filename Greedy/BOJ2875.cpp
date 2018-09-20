#include <iostream>

int main()
{
	int N, M, K;
	std::cin >> N >> M >> K;

	while (K--)
	{
		if (M > N / 2)
			--M;
		else
			--N;
	}

	if (N / 2 <= M)
		std::cout << N / 2;
	else
		std::cout << M;

	return 0;
}
