#include <iostream>
#include <vector>
#include <cmath>

int perfect[4] = { 2, 3, 5, 7 };
std::vector<int> v[4];

int main()
{
	int n;

	for (int i = 0; i < 4; ++i)
	{
		perfect[i] = std::pow(2, perfect[i] - 1) * (std::pow(2, perfect[i]) - 1);
		for (int j = 1; j <= perfect[i] / 2; ++j)
		{
			if (perfect[i] % j == 0)
				v[i].push_back(j);
		}
	}

	while (true)
	{
		std::cin >> n;
		if (n == -1) break;

		if (n % 2 == 1) std::cout << n << " is NOT perfect." << '\n';
		else
		{
			bool check = false;
			for (int i = 0; i < 4; ++i)
			{
				if (n == perfect[i])
				{
					check = true;
					std::cout << n << " = 1 ";
					for (int j = 1; j < v[i].size(); ++j)
						std::cout << "+ " << v[i][j] << ' ';
					std::cout << '\n';
					break;
				}
			}
			if(!check) std::cout << n << " is NOT perfect." << '\n';
		}
	}

	return 0;
}
