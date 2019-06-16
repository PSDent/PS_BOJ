#include <iostream>
#include <vector>
#include <algorithm>

int GCD(int a, int b)
{
	return a % b ? GCD(b, a % b) : b;
}

int main()
{
	int N;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::vector<int> v;
		int len;
		std::cin >> len;
		for (int j = 0; j < len; ++j)
		{
			int input;
			std::cin >> input;
			v.push_back(input);
		}
		std::sort(v.begin(), v.end(), std::greater<int>());

		long long sum = 0;
		for (int m = 0; m < len - 1; ++m)
		{
			for (int n = m + 1; n < len; ++n)
				sum += GCD(v[m], v[n]);
		}
		std::cout << sum << '\n';
	}

	return 0;
}