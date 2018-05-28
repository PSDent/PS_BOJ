#include <iostream>

int paper[2188][2188];
int cnt[3];

void CountPaper(int sx, int sy, int size)
{
	int pivot = paper[sy][sx];

	for (int i = sy; i < sy + size; i++)
	{
		for (int j = sx; j < sx + size; j++)
		{
			// 밑의 조건이 문제임. 
			if (paper[i][j] != pivot)
			{
				for (int m = 0; m < 3; ++m)
					for (int n = 0; n < 3; ++n)
						CountPaper(sx + n * (size / 3), sy + m * (size / 3),  size / 3);
				return;
			}
				
		}
	}
	++cnt[pivot + 1];
}

int main()
{
	int N;

	std::cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			std::cin >> paper[i][j];

	CountPaper(1, 1, N);

	for (int i = 0; i < 3; i++)
		std::cout << cnt[i] << '\n';

	return 0;
}