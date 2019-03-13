#include <iostream>
#include <list>

int main()
{
	std::list<int> ls;
	std::list<int>::iterator iter;
	int N, M;
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		ls.push_back(i);

	iter = ls.begin();
	std::advance(iter, M - 1);
	std::cout << '<';
	while (ls.size())
	{
		std::cout << *iter;
		iter = ls.erase(iter);
		if (iter == ls.end()) iter = ls.begin();

		if (!ls.size()) break;
		else std::cout << ", ";
		int cnt = M - 1;
		while (cnt--)
		{
			++iter;
			if (iter == ls.end())
				iter = ls.begin();
		}
	}
	std::cout << '>';

	return 0;
}
