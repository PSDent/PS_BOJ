#include <iostream>
#include <cmath>

long long A, B, n;

int main()
{
	std::cin >> A >> B;
	n = std::abs(B - A) + (long long)1;
	std::cout << n * (A + B) / (long long)2;
	return 0;
}
