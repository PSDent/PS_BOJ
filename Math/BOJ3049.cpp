#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	std::cout << N * (N - 1) * (N - 2) * (N - 3) / 24;
	return 0;
}
