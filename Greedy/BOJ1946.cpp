#include <iostream>
#include <vector>
#include <algorithm>

using Worker = std::pair<int, int>;
int minimum[100000];

int main()
{
	std::ios::sync_with_stdio(false);
	int T, N, input1, input2;

	std::cin >> T;
	for (int i = 0; i < T; ++i)
	{
		std::vector<Worker> v;

		std::cin >> N;
		for (int j = 0; j < N; ++j)
		{
			std::cin >> input1 >> input2;
			v.push_back(std::make_pair(input1, input2));
		}

		int pass = v.size();
		std::sort(v.begin(), v.end());

		int min = 100000;
		for (int j = 0; j < v.size(); ++j)
		{
			if (min > v[j].second)
				min = v[j].second;
			minimum[j] = min;
		}

		for (int j = 0; j < v.size(); ++j)
			if (v[j].second > minimum[j])
				--pass;
		std::cout << pass << '\n';
	}

	return 0;
}
