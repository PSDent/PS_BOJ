#include <iostream>
#include <algorithm>

int main()
{
	int oddNum[7];
	int index = 0, sum = 0;

	for (int i = 0; i < 7; ++i)
	{
		int input;
		std::cin >> input;
		if (input % 2 == 1)
		{
			sum += input;
			oddNum[index++] = input;
		}
	}

	std::sort(oddNum, oddNum + index);

	if (index == 0)
		std::cout << -1;
	else
	{
		std::cout << sum << '\n';
		std::cout << oddNum[0];
	}

	return 0;
}
