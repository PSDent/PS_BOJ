#include <iostream>

int card[4][101], player[201][4], score[201];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			int input;
			std::cin >> input;
			player[i][j] = input;
			++card[j][input];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			int num = player[i][j];
			if (card[j][num] == 1)
				score[i] += num;
		}
		std::cout << score[i] << '\n';
	}

	return 0;
}
