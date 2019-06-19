#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using User = std::pair<int, std::string>;

bool cmp(const User &l, const User &r)
{
	return l.first < r.first;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<User> v;
	for (int i = 0; i < N; ++i)
	{
		int age;
		std::string name;
		std::cin >> age >> name;
		v.emplace_back(age, name);
	}

	std::stable_sort(v.begin(), v.end(), cmp);

	for (auto user : v)
		std::cout << user.first << ' ' << user.second << '\n';

	return 0;
}
