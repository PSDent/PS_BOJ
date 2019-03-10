#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	int T, N, K, type;
	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> K;
		int child = 0;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> type;
			child += type / K;
		}
		std::cout << child << '\n';
	}


	return 0;
}
