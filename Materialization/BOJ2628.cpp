#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> line[2];
int width, height, max;

int main()
{
	int N, no, val;
	std::cin >> width >> height >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> no >> val;
		line[no].push_back(val);
	}
	line[0].push_back(height);
	line[1].push_back(width);

	std::sort(line[0].begin(), line[0].end(), std::less<int>());
	std::sort(line[1].begin(), line[1].end(), std::less<int>());

	int w, h;
	for (int i = 0; i < line[0].size(); ++i) // 0 - 가로, 1 - 세로
	{
		if (i > 0) h = line[0][i] - line[0][i-1];
		else h = line[0][i];
		for (int j = 0; j < line[1].size(); ++j)
		{
			if (j > 0) w = line[1][j] - line[1][j - 1];
			else w = line[1][j];
			
			max = std::max(max, h * w);
		}
	}
	std::cout << max;

	return 0;
}
