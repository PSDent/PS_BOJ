#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int add = i % 2 ? 1 : 0;
		for (int j = add; j < N * 2 + add; ++j)
		{
			if (j % 2 == 1)
				std::cout << ' ';
			else
				std::cout << '*';
		}
		std::cout << '\n';
	}

	return 0;
}
