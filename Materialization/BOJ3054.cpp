#include <iostream>
#include <string>
#include <cstring>

char board[6][76];

int main()
{
	std::ios::sync_with_stdio(false);
	std::string input;

	for (int i = 1; i < 6; ++i)
		memset(board[i], '.', sizeof(board[i]));

	std::cin >> input;

	for (int i = 1; i <= input.length(); ++i)
	{
		int center = 3 + (i - 1) * 4;
		board[3][center] = input[i - 1];

		if (i % 3 == 0) continue;

		int sx = (i-1) * 5 + 1;
		for (int j = 0; j < 5; ++j)
		{
			int offset = j;
			if (j >= 3)
				offset = 4 - j;
			board[j + 1][center - offset] = '#';
			board[j + 1][center + offset] = '#';
		}
	}

	for (int i = 1; i <= input.length(); ++i)
	{
		int center = 3 + (i - 1) * 4;
		if (i % 3 != 0) continue;

		int sx = (i - 1) * 5 + 1;
		for (int j = 0; j < 5; ++j)
		{
			int offset = j;
			if (j >= 3)
				offset = 4 - j;
			board[j + 1][center - offset] = '*';
			board[j + 1][center + offset] = '*';
		}
	}

	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= input.length() * 5 - (input.length()-1); ++j)
			std::cout << board[i][j];
		std::cout << '\n';
	}

	return 0;
}
