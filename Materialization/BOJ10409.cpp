#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	int N, T, work = 0, input;
	std::cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		if ((T -= input) < 0) break;
		++work;
	}
	std::cout << work;

	return 0;
}
