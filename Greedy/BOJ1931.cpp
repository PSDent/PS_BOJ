#include <iostream>
#include <vector>
#include <algorithm>

using Talk = std::pair<int, int>;
int N, max = 1;

bool cmp(Talk &left, Talk &right)
{
	if (left.second != right.second)
		return left.second < right.second ? true : false;
	else
		return left.first < right.first ? true : false;
}

int main()
{
	std::vector<Talk> v;
	int a, b;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
	}

	std::sort(v.begin(), v.end(), cmp);
	int next = v[0].second;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].first >= next)
		{
			next = v[i].second;
			++max;
		}
	}
	std::cout << max;
	return 0;
}
