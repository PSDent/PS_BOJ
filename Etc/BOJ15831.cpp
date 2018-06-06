#include <iostream>

int blackIndex[300005], index = 1;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N, W, B, cnt;
	int max = 0;

	std::cin >> N >> B >> W;

	char input;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> input;
		if (input == 'B')
			blackIndex[index++] = i;
	}

	blackIndex[0] = 0;
	blackIndex[index] = N + 1;

	for (int i = 0; i <= index; ++i)
	{
		if (index > B)
		{
			if (i + B + 1 > 300004)
				break;
				
			cnt = blackIndex[i + B + 1] - blackIndex[i] - 1;
			if (cnt - B >= W)
				max = Max(max, cnt);
		}
		else
		{
			if (i + index > 300004)
				break;

			cnt = blackIndex[i + index] - blackIndex[i] - 1;
			if (cnt - (index - 1) >= W)
				max = Max(max, cnt);
		}
	}

	std::cout << max;

	return 0;
}
