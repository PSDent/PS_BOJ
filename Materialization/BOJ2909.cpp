#include <iostream>
#include <cmath>

int main()
{
	int C, K;
	std::cin >> C >> K;
	int money = pow(10, K);
	double quot = floor(C / (double)money + 0.5);

	if (C == money) std::cout << C;
	else std::cout << (int)(quot * money);

	return 0;
}
