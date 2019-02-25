#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	std::vector<int> file;
	int N, input, size;
	long long sum = 0;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		file.push_back(input);
	}
	std::cin >> size;

	for (int i = 0; i < N; ++i)
	{
		if (file[i] == 0) continue;
		if (file[i] % size == 0)
			sum += (file[i] / size) * size;
		else
			sum += (file[i] / size + 1) * size;
	}
	std::cout << sum;

	return 0;
}
