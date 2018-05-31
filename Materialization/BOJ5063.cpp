#include <iostream>

int main()
{
	int n;
	int r, e, c;

	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> r >> e >> c;

		if (r > e - c)
			std::cout << "do not advertise" << '\n';
		else if (r < e - c)
			std::cout << "advertise" << '\n';
		else
			std::cout << "does not matter" << '\n';
	}



	return 0;
}
