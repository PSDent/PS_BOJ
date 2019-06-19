#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using Card = std::pair<long long, int>;

bool cmp(const Card &l, const Card &r)
{
	if (l.second == r.second)
		return l.first < r.first;
	else
		return l.second > r.second;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::map<long long, int> m;
	for (int i = 0; i < N; ++i)
	{
		long long input;
		std::cin >> input;

		if (m.find(input) == m.end())
			m[input] = 1;
		else
			++m[input];
	}

	std::vector<Card> v;
	for (auto card : m)
		v.emplace_back(card.first, card.second);

	std::sort(v.begin(), v.end(), cmp);
	std::cout << v[0].first;

	return 0;
}
