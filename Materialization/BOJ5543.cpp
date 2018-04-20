#include <iostream>

int Min(int a, int b) {
	return a > b ? b : a;
}

int main()
{
	int ham[3];
	int drink[2];

	std::cin >> ham[0] >> ham[1] >> ham[2] >> drink[0] >> drink[1];

	std::cout << Min(Min(ham[0], ham[1]), ham[2]) + Min(drink[0], drink[1]) - 50;

	return 0;
}
