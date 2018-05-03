#include <iostream>
#include <algorithm>

int main()
{
	int N, sum = 0;
	int P[1001];
	
	std::cin >> N;

	for (int i = 1; i <= N; i++)
		std::cin >> P[i];

	std::sort(P + 1, P + N+1);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			sum += P[j];

	std::cout << sum;

	return 0;
}
