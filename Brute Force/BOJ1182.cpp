#include <iostream>

int N, S, cnt = 0;
int arr[20];

void SumAmount(int index, int sum)
{
	if (sum == S)
		++cnt;

	for (int i = index + 1; i < N; ++i)
		SumAmount(i, sum + arr[i]);
}

int main()
{
	std::cin >> N >> S;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	for (int i = 0; i < N; ++i)
		SumAmount(i, arr[i]);
	std::cout << cnt;

	return 0;
}
