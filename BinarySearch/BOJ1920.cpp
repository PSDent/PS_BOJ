#include <iostream>
#include <algorithm>

int N, M;
int ques[100000];
int arr[100000];

void BinarySearch(int val)
{
	int low = 0, high = N - 1;
	int mid = high / 2;

	while (low <= high)
	{
		if (arr[mid] > val)
			high = mid - 1;
		else if (arr[mid] < val)
			low = mid + 1;
		else
		{
			std::cout << 1 << '\n';
			return;
		}
		mid = (high + low) / 2;
	}
	std::cout << 0 << '\n';
}

int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
	std::cin >> M;
	for (int i = 0; i < M; ++i)
		std::cin >> ques[i];

	std::sort(arr, arr + N);

	for (int i = 0; i < M; ++i)
		BinarySearch(ques[i]);

	return 0;
}