#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> v;

int main()
{
	int N, a, b;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
	}

	for (int i = 0; i < N; ++i)
	{
		int rank = 1;
		for (int j = 0; j < N; ++j)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				++rank;
		}
		std::cout << rank << ' ';
	}

	return 0;
}
