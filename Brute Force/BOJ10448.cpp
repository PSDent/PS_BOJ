#include <iostream>

int table[1001];
bool possible[1001];

void triSum(int sum, int step)
{ 
	if (possible[sum] && step == 3 || step > 3) return;
	if (sum <= 1000 && step == 3)
	{
		possible[sum] = true;
		return;
	}

	for(int i = 1; i <= 50; ++i)
		triSum(sum + table[i], step + 1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 1; i <= 50; ++i)
		table[i] = (i * (i + 1)) / 2;
	for (int i = 1; i <= 50; ++i)
		triSum(table[i], 1);

	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int input;
		std::cin >> input;
		std::cout << (int)possible[input] << '\n';
	}

	return 0;
}
