#include <iostream>
const int LIMIT = 210;

int main()
{
	int K, N, T, time = 0;
	char Z;
	std::cin >> K >> N;
	K -= 1;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> T >> Z;
		time += T;
		if (time >= LIMIT) break;
		if (Z == 'T') K = (K + 1) % 8;
	}

	std::cout << K + 1;

	return 0;
}
