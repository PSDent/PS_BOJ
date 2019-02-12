#include <iostream>
#include <string>

int main()
{
	std::string str[51];
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
		std::cin >> str[i];

	for (int j = 0; j < str[1].size(); ++j)
	{
		char prev = str[1][j];
		bool fail = false;
		for (int i = 1; i <= N; ++i)
		{
			if (str[i][j] != prev)
			{
				fail = true;
				break;
			}
		}

		if (!fail)
			std::cout << str[1][j];
		else
			std::cout << '?';
	}

	return 0;
}
