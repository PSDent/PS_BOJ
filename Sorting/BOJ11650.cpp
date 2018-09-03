#include <iostream>
#include <vector>
#include <algorithm>

using Point = std::pair<int, int>;

int N;
std::vector<Point> v;

bool Cmp(const Point &a, const Point &b)
{
	if (a.first != b.first)
		return a.first < b.first ? true : false;
	else
		return a.second < b.second ? true : false;
}

int main()
{
	int x, y;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x >> y;
		v.push_back(std::make_pair(x, y));
	}

	std::sort(v.begin(), v.end(), Cmp);

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i].first << ' ' << v[i].second << '\n';
	return 0;
}
