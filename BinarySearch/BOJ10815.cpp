#include <iostream>
#include <ios>

bool val_p[10000001], val_m[10000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M, N, input;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> input;
		if (input <= 0) val_m[-input] = true;
		else val_p[input] = true;
	}

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		if (input <= 0) std::cout << val_m[-input] << ' ';
		else std::cout << val_p[input] << ' ';
	}

	return 0;
}
