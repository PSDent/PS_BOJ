#include <iostream>

int main()
{
	int arr[8], cnt = 0;

	for (int i = 0; i < 8; ++i)
		std::cin >> arr[i];

	for (int i = 0; i < 7; ++i)
	{
		if ( (arr[i] == i + 1 && arr[i+1] == arr[i] + 1) ||
			(arr[i] == 8 - i && arr[i+1] == arr[i] - 1) )
		{
			++cnt;
		}
		else
		{
			std::cout << "mixed";
			return 0;
		}
	}

	if (arr[0] == 8)
		std::cout << "descending";
	else
		std::cout << "ascending";

	return 0;
}