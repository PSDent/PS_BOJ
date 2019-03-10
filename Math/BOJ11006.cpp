#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	int T, N, M;
	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> M;
		std::cout << M - (N - M) << ' ' << N - M << '\n';
	}

	return 0;
}
