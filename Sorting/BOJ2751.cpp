#include <iostream>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::map<int, int> m;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;
		if (!m[input])
			m[input] = input;
	}

	for (auto val : m)
		std::cout << val.first << '\n';

	return 0;
}
