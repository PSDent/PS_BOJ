#include <iostream>

int main()
{
	int sum = 0, total;

	std::cin >> total;
	for (int i = 0; i < 9; ++i)
	{
		int input;
		std::cin >> input;
		sum += input;
	}

	std::cout << total - sum;

	return 0;
}
