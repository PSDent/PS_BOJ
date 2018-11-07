#include <iostream>
#include <limits>
#include <ios>

using Point = std::pair<int, int>;

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	Point p[4];

	std::cin >> T;
	for (int i = 0; i < T; ++i)
	{
		long long line = std::numeric_limits<long long>::max(), diag = 0;
		for (int j = 0; j < 4; ++j)
		{
			std::cin >> p[j].first >> p[j].second;
			if (j != 0)
			{
				long long tempX = (p[0].first - p[j].first) * (p[0].first - p[j].first);
				long long tempY = (p[0].second - p[j].second) * (p[0].second - p[j].second);
				long long dist = tempX + tempY;

				if (diag < dist)
				{
					line = diag;
					diag = dist;
				}
				else
					line = dist;
			}
		}
		bool isDiff = false;
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			 {
				if (j == k) continue;
				long long tempX = (p[j].first - p[k].first) * (p[j].first - p[k].first);
				long long tempY = (p[j].second - p[k].second) * (p[j].second - p[k].second);
				long long dist = tempX + tempY;
				if (dist != line && dist != diag) isDiff = true;
			}
		}
		if (isDiff) std::cout << '0' << '\n';
		else std::cout << '1' << '\n';
	}
	return 0;			
}
