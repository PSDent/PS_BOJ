#include <iostream>

int main()
{
	int A, B, C, K;
	std::cin >> A >> B >> C;

	if (C - B <= 0) std::cout << -1;
	else
		std::cout << A / (C - B) + 1;

	return 0;
}
