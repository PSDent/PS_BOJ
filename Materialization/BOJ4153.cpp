#include <iostream>
#include <cmath>

int main()
{
	int a, b, c;

	while (true)
	{
		std::cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) return 0;
		if (pow(a, 2) == pow(b, 2) + pow(c, 2)
			|| pow(b, 2) == pow(a, 2) + pow(c, 2)
			|| pow(c, 2) == pow(a, 2) + pow(b, 2))
			std::cout << "right" << '\n';
		else
			std::cout << "wrong" << '\n';
	}
}
