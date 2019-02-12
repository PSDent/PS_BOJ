#include <iostream>

char card[101][101], input;
int R, C;

int main()
{
	int A, B;
	std::cin >> R >> C;

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			std::cin >> input;
			card[i][j] = input;
			card[i][C * 2 - j + 1] = input;
			card[R * 2 - i + 1][j] = input;
			card[R * 2 - i + 1][C * 2 - j + 1] = input;
		}
	}
	std::cin >> A >> B;
	if (card[A][B] == '.') card[A][B] = '#';
	else card[A][B] = '.';

	for (int i = 1; i <= R * 2; ++i)
	{
		for (int j = 1; j <= C * 2; ++j)
			std::cout << card[i][j];
		std::cout << '\n';
	}

	return 0;
}
