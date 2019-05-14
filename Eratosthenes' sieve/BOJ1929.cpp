#include <iostream>
#include <cstring>

const int Max = 1000000;
bool prime[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	int N, M;

	std::cin >> M >> N;

	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i * i <= Max; ++i)
	{
		if(prime[i])
			for (int j = i * 2; j <= Max; j += i)
				prime[j] = false;
	}

	for (int i = M; i <= N; ++i)
		if (prime[i])
			std::cout << i << '\n';
	return 0;
}