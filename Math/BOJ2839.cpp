#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	int num5 = N / 5, num3 = (N % 5) / 3;

	while (true)
	{
		int cnt = num5 * 5 + num3 * 3;
		if (cnt == N)
			break;
		else
		{
			if (num5 == 0)
			{
				std::cout << -1;
				return 0;
			}
			else
			{
				--num5;
				num3 = (N - num5 * 5) / 3;
			}
		}
	}

	std::cout << num3 + num5;

	return 0;
}
