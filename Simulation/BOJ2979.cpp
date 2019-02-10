#include <iostream>

int cost[101], park[4];

int main()
{
	int s,e, money = 0;

	std::cin >> park[1] >> park[2] >> park[3];
	for (int i = 0; i < 3; ++i)
	{
		std::cin >> s >> e;
		for (int j = s; j < e; ++j)
			++cost[j];
	}

	for (int i = 1; i <= 100; ++i)
		money += park[cost[i]] * cost[i];
	std::cout << money;

	return 0;
}
