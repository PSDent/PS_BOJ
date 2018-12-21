#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = N; j > i; --j)
			std::cout << ' ';
		for (int j = 0; j < i; ++j)
			std::cout << '*';
		std::cout << '\n';
	}

	return 0;
}