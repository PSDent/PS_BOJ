#include <iostream>
#include <vector>
#include <algorithm>

using Point = std::pair<int, int>;

bool cmp(Point &l, Point &r)
{
	if (l.second == r.second)
		return l.first < r.first;
	else
		return l.second < r.second;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<Point> v;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		v.emplace_back(x, y);
	}

	std::sort(v.begin(), v.end(), cmp);

	for (auto point : v)
	{
		std::cout << point.first << ' ' << point.second << '\n';
	}

	return 0;
}
