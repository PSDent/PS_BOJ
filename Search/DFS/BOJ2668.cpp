#include <iostream>
#include <vector>
#include <algorithm>

int num[101];
bool visited[101];
std::vector<int> v;

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
		std::cin >> num[i];

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i]) continue;

		std::vector<int> tempV;
		int cnt = 1, next = i;
		while (++cnt <= N)
		{
			tempV.push_back(next);
			next = num[next];

			if (next == i)
			{
				for (int j = 0; j < tempV.size(); ++j)
					visited[tempV[j]] = true;
				v.insert(v.end(), tempV.begin(), tempV.end());
				break;
			}
		}
	}

	std::sort(v.begin(), v.end());
	std::cout << v.size() << '\n';
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << '\n';

	return 0;
}
