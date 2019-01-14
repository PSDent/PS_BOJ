#include <iostream>
#include <cmath>

void Hanoi(int n, int from, int mid, int to)
{
	if (n == 1)
		std::cout << from << ' ' << to << '\n';
	else
	{
		Hanoi(n - 1, from, to, mid);
		std::cout << from << ' ' << to << '\n';
		Hanoi(n - 1, mid, from, to);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::cout << (int)pow(2, N) - 1 << '\n';
	Hanoi(N, 1, 2, 3);

	return 0;
}
