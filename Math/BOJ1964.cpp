#include <iostream>

using ll = long long;

int main()
{
	int N;
	std::cin >> N;
	std::cout << (ll)((ll)((ll)(N - 1) * (ll)(3 * N + 1 + 7)) / (ll)2 + 5) % (ll)45678;

	return 0;
}
