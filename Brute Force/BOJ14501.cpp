#include <iostream>

int N, max = 0;
int T[16];
int P[16];

int Max(int a, int b)
{
	return a > b ? a : b;
}

void Search(int index, int income)
{
	if (index + T[index] > N+1)
		return;

	for (int i = index + T[index]; i <= N; ++i)
		Search(i, income + P[i]);

	max = Max(max, income);
}

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
		std::cin >> T[i] >> P[i];
	for (int i = 1; i <= N; ++i)
		Search(i, P[i]);

	std::cout << max;
}
