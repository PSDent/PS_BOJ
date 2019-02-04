#include <iostream>

int arr[101], sum[101];

int main()
{
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
		std::cin >> arr[i];
	sum[1] = arr[1];
	std::cout << sum[1] << ' ';
	for (int i = 2; i <= N; ++i)
	{
		int elem = arr[i] * i - sum[i - 1];
		sum[i] = sum[i - 1] + elem;
		std::cout << elem << ' ';
	}

	return 0;
}
