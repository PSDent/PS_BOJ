#include <iostream>

int A[1000001];

int main()
{
	int N, K, cnt = 0;

	std::cin >> N >> K;

	for (int i = 1; i <= N; i++)
		std::cin >> A[i];

	for (int i = N; K > 0; --i)
	{
		int share = K / A[i];
		cnt += share;

		K -= share * A[i];
	}

	std::cout << cnt;

	return 0;
}
