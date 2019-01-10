#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	int outLayer = 1;
	int mul = 1;

	while (outLayer < N)
	{
		outLayer += mul * 6;
		++mul;
	}

	std::cout << mul;

	return 0;
}