#include <iostream>
#include <cstring>
#include <vector>

const int MAX = 1000000;
bool primeCheck[MAX + 1];
int startIndex[MAX + 1];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::vector<int> v;

	memset(primeCheck, true, sizeof(primeCheck));
	for (int i = 2; i <= MAX; ++i)
	{
		if (primeCheck[i])
		{
			v.push_back(i);

			if(i * i <= MAX)
				for (int j = i * 2; j <= MAX; j += i)
					primeCheck[j] = false;
		}
		else
			startIndex[i] = v.size() - 1;
	}

	while (true)
	{
		int input;
		std::cin >> input;

		if (input == 0) break;

		int rightIndex = startIndex[input];
		int right = v[rightIndex];
		int left;
		while (true)
		{
			if (input - right <= 2)
			{
				--rightIndex;
				right = v[rightIndex];
			}

			if (primeCheck[input - right])
			{
				left = input - right;
				break;
			}
			else
			{
				--rightIndex;
				right = v[rightIndex];
			}
		}
		std::cout << input << " = " << left << " + " << right << '\n';
	}

	return 0;
}
