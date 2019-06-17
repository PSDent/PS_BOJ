#include <iostream>
#include <cstring>
#include <vector>

const int MAX = 10000000;
bool num[MAX + 1];

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	std::cin >> N;

	std::vector<int> primeNum;
	memset(num, true, sizeof(num));

	for (int i = 2; i <= MAX; ++i)
	{
		if (num[i])
		{
			primeNum.push_back(i);
			if (i * i <= MAX)
			{
				for (int j = i * 2; j <= MAX; j += i)
					num[j] = false;
			}
		}
	}

	for (int i = 0; i < primeNum.size(); ++i)
	{
		while (N % primeNum[i] == 0)
		{
			N /= primeNum[i];
			std::cout << primeNum[i] << '\n';
			if (N == 0) return 0;
		}
	}

	return 0;
}
