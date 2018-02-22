#include <iostream>

int main()
{
	int N, sum = 1;

	std::cin >> N;

	for (int i = N; i > 0; i--) {
		sum *= i;
	}

	std::cout << sum << std::endl;

	return 0;
}