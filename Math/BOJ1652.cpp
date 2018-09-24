#include <iostream>

int main()
{
	int N, wCnt = 0, hCnt = 0;
	char room[101][101];
	std::cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			std::cin >> room[i][j];

	for (int i = 0; i < N; ++i)
	{
		int wIndex = 0;
		int hIndex = 0;
		while (wIndex < N)
		{
			int cnt = 0;
			while (room[i][wIndex] == 'X') ++wIndex;
			while (room[i][wIndex] == '.') { ++wIndex; ++cnt; };
			if (cnt >= 2)
				++wCnt;
		}

		while (hIndex < N)
		{
			int cnt = 0;
			while (room[hIndex][i] == 'X') ++hIndex;
			while (room[hIndex][i] == '.') { ++hIndex; ++cnt; };
			if (cnt >= 2)
				++hCnt;
		}
	}

	std::cout << wCnt << ' ' << hCnt;

	return 0;
}
