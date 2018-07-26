#include <iostream>

int M, N;
int max;
int arr[100];

int MaxInRange(int a, int b)
{
	if (a > M || b > M)
		return (M - a) > (M - b) ? a : b;
	else
		return a > b ? a : b;
}

void BlackJack(int index, int val, int cnt)
{
	if (cnt == 3)
	{
		max = MaxInRange(max, val);
		return;
	}

	for (int i = index + 1; i < N; ++i)
		BlackJack(i, val + arr[i], cnt + 1);
}

int main()
{
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	for(int i = 0; i < N; ++i)
		BlackJack(i, arr[i], 1);
	std::cout << max;
	return 0;
}
