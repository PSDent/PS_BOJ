#include <iostream>

int main()
{
	int N, num[3];

	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> num[i];
	for (int i = 1; i <= 100000000; ++i)
	{
		bool check = true;
		if (N == 2 && num[0] % i == 0 && num[1] % i == 0)
			std::cout << i << '\n';
		else if (N == 3 && num[0] % i == 0 && num[1] % i == 0 && num[2] % i == 0)
			std::cout << i << '\n';
	}

	return 0;
}
