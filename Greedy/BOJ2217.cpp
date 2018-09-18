#include <iostream>
#include <vector>
#include <algorithm>

int N;

int main()
{
	int input, max = 0;
	std::vector<int> v;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		v.push_back(input);
	}

	std::sort(v.begin(), v.end(), std::greater<int>());

	for (int i = 0; i < N; ++i)
	{
		if (max < v[i] * (i + 1))
			max = v[i] * (i + 1);
	}
	std::cout << max;
	return 0;
}
