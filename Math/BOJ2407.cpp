#include <iostream>
#include <deque>

std::deque<char> pasTri[101][101];

int main()
{
	int n, m;
	std::cin >> n >> m;

	pasTri[0][0].push_back('1');
	for (int i = 1; i <= n; ++i)
	{
		pasTri[i][0].push_back('1');
		pasTri[i][i].push_back('1');

		for (int j = 1; j <= i - 1; ++j)
		{
			std::deque<char> big = (pasTri[i - 1][j - 1].size() >= pasTri[i - 1][j].size()) ? pasTri[i - 1][j - 1] : pasTri[i - 1][j];
			std::deque<char> small = (pasTri[i - 1][j - 1].size() >= pasTri[i - 1][j].size()) ? pasTri[i - 1][j] : pasTri[i - 1][j - 1];
			
			int sSize = small.size(), bSize = big.size();
			int val, carry = 0;
			for (int k = 1; k <= big.size(); ++k)
			{
				if (sSize - k >= 0)
					val = big[bSize - k] + small[sSize - k] - ('0' * 2);
				else
					val = big[bSize - k] - '0';

				if (val >= 10)
				{
					if (k < bSize)
						big[bSize - k - 1] += 1;
					else
					{
						pasTri[i][j].push_front((char)(val - 10 + '0'));
						pasTri[i][j].push_front((char)('1'));
						break;
					}
					val -= 10;
				}
				pasTri[i][j].push_front((char)(val + '0'));
			}

		}
	}

	for (int i = 0; i < pasTri[n][m].size(); ++i)
		std::cout << pasTri[n][m][i];

	return 0;
}
