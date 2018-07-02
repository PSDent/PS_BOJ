#include <iostream>
#include <iomanip>

int main()
{
	int T;

	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int n, p = 0;
		double gp = 0.0;
		std::cin >> n;

		for (int j = 0; j < n; ++j)
		{
			int pInput;
			double gpInput;

			std::cin >> pInput >> gpInput;
			p += pInput;
			gp += pInput * gpInput;
		}
		gp /= p;

		std::cout << std::fixed << std::setprecision(1);
		std::cout << p << ' ' << gp << '\n';
	}

	return 0;
}
