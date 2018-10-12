#include <iostream>

int cook[5][5];
int num;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cin >> cook[i][j];
			cook[i][4] += cook[i][j];
		}
		num = cook[i][4] > cook[num][4] ? i : num;
	}

	std::cout << num + 1 << ' ' << cook[num][4];

	return 0;
}
