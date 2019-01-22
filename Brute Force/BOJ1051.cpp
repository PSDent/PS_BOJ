#include <iostream>
#include <algorithm>

char box[52][52];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			std::cin >> box[i][j];


	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			for (int k = 1; k < N + M; ++k)
			{
				if (i + k > N || j + k > M) break;

				int left = j, right = j + k, bot = i + k, top = i;

				if (box[top][left] == box[top][right] && box[top][left] == box[bot][left]
					&& box[top][left] == box[bot][right])
					max = std::max(max, k);
			}

		}
	}
	max += 1;
	std::cout << max * max;

	return 0;
}
