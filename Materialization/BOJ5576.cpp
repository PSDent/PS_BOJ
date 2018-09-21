#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
	std::vector<int> v1, v2;
	int input;

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> input;
		v1.push_back(input);
	}
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> input;
		v2.push_back(input);
	}

	std::sort(v1.begin(), v1.end(), std::greater<int>());
	std::sort(v2.begin(), v2.end(), std::greater<int>());

	std::cout << v1[0] + v1[1] + v1[2] << '\n';
	std::cout << v2[0] + v2[1] + v2[2] << '\n';

	return 0;
}
