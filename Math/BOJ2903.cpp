#include <iostream>
#include <cmath>

int main()
{
	int N;
	std::cin >> N;
	std::cout << (int)std::pow(((std::pow(2, N) - 1) + 2), 2);

	return 0;
}
