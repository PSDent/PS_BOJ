#include <iostream>
#include <algorithm>
#include <vector>

int N, K;
std::vector<int> v;

int main()
{
	std::ios::sync_with_stdio(false);

	int input;
	std::cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		v.push_back(input);
	}

	std::nth_element(v.begin(), v.begin() + K - 1, v.end());
	std::cout << v[K - 1];

	return 0;
}
