#include <iostream>
#include <list>

std::list<int> lst;

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
		lst.emplace_back(i);

	std::list<int>::iterator iter;
	while (lst.size() > 1)
	{
		std::cout << *lst.begin() << ' ';
		lst.erase(lst.begin());
		lst.push_back(*lst.begin());
		lst.erase(lst.begin());
	}
	std::cout << *lst.begin();

	return 0;
}
