#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Grades
{
	std::string name;
	int korean, english, math;
};

bool cmp(const Grades &left, const Grades &right)
{
	if (left.korean == right.korean)
	{
		if (left.english == right.english)
		{
			if (left.math == right.math)
				return (left.name.compare(right.name) < 0);
			return left.math > right.math;
		}
		return left.english < right.english;
	}
	return left.korean > right.korean;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<Grades> v;
	for (int i = 0; i < N; ++i)
	{
		std::string name;
		int korean, english, math;
		std::cin >> name >> korean >> english >> math;
		v.emplace_back(Grades{ name, korean, english, math });
	}
	std::sort(v.begin(), v.end(), cmp);

	for (auto grade : v)
		std::cout << grade.name << '\n';

	return 0;
}
