#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using Data = std::pair<std::string, int>;
std::vector<Data> v;

struct cmp
{
	bool operator() (const Data &l, const Data &r)
	{
		if (l.second == r.second)
			return std::less<std::string>() (l.first, r.first);
		else
			return std::greater<int>() (l.second, r.second);
	}
};

int main()
{
	std::map<std::string, int> m;
	std::string input;
	std::ios::sync_with_stdio(false);
	int N, max = 0;
	std::cin >> N;
	while (N--)
	{
		std::cin >> input;
		if (m.find(input) != m.end())
			++m.find(input)->second;
		else
			m.insert(std::make_pair(input, 1));
	}

	for (auto iter = m.begin(); iter != m.end(); ++iter)
		v.emplace_back(std::make_pair(iter->first, iter->second));
	std::sort(v.begin(), v.end(), cmp());

	std::cout << v[0].first;

	return 0;
}
