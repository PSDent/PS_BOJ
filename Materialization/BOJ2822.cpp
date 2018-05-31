#include <iostream>
#include <algorithm>

int answer[2][9];

void sort()
{
	for (int i = 8; i > 1; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			//int temp = answer[0][i];
			if (answer[0][j] < answer[0][j + 1])
			{
				int temp = answer[0][j + 1];
				answer[0][j + 1] = answer[0][j];
				answer[0][j] = temp;

				int tIndex = answer[1][j + 1];
				answer[1][j + 1] = answer[1][j];
				answer[1][j] = tIndex;
			}
		}
	}
	return;
}

int main()
{
	int sum = 0;

	for (int i = 1; i <= 8; ++i) {
		std::cin >> answer[0][i];
		answer[1][i] = i;
	}

	sort();

	for (int i = 1; i <= 5; ++i)
		sum += answer[0][i];

	std::cout << sum << '\n';

	std::sort( (*(answer + 1) + 1), (*(answer + 1) + 6) );
	for (int i = 1; i <= 5; ++i)
		std::cout << answer[1][i] << ' ';




	return 0;
}
