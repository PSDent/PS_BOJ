#include <iostream>

int main()
{
	int T, V, E;

	std::cin >> T;
	for (int i = 0; i < T; ++i)
	{
		std::cin >> V >> E;
		std::cout << E - V + 2 << '\n';
	}

	return 0;
}
