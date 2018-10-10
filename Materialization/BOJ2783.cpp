#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::pair<float, float>> v;
int N;

int main()
{
	float X, Y;

	std::cin >> X >> Y;
	Y /= X; X = 1;
	v.push_back(std::make_pair(X, Y));
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> X >> Y;
		Y /= X;
		X = 1;
		v.push_back(std::make_pair(X, Y));
	}
	std::sort(v.begin(), v.end(), std::greater<std::pair<float, float>>());

	std::cout << std::fixed << std::setprecision(2) << (1000.0f / v[0].second) * v[0].first;

	return 0;
}
