#include <iostream>
#include <cmath>

bool box[6562][6562];
int maxLevel, N;

void Box(int left, int top, int right, int bot, int level)
{
	if (level > maxLevel)
		return;

	for (int i = 0; i <= right - left; ++i)
	{
		box[top][left + i] = box[bot][left + i] = true;
		box[top + i][left] = box[top + i][right] = true;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1) continue; // 중간을 비워둔다.

			int nLeft = left + (N / pow(3, level)) * j;
			int nTop = top + (N / pow(3, level)) * i;
			int nRight = nLeft + (N / pow(3, level)) - 1;
			int nBot = nTop + (N / pow(3, level)) - 1;

			Box(nLeft, nTop, nRight, nBot, level + 1);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	std::cin >> N;

	maxLevel = log10(N) / log10(3); // log a K = log K / log a

	if (N > 1)
		Box(1, 1, N, N, 1);
	else
	{
		std::cout << '*';
		return 0;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			if (box[i][j])
				std::cout << '*';
			else
				std::cout << ' ';
		std::cout << '\n';
	}

	return 0;
}
