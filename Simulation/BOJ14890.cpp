#include <iostream>
#include <cmath>
#include <vector>

using Data = std::pair<int, int>; // 높이, 칸 수

int N, L;
int map[101][101];
std::vector<Data> wV[101], hV[101];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> L;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			std::cin >> map[i][j];

	for (int i = 1; i <= N; ++i) // 압축
	{
		int wCnt = 0, hCnt = 0;
		int wPrev = map[i][1], hPrev = map[1][i];
		for (int j = 1; j <= N + 1; ++j)
		{
			if (j <= N && map[i][j] == wPrev) ++wCnt;
			else if(j == N + 1 || map[i][j] != wPrev)
			{
				wV[i].emplace_back(Data(wPrev, wCnt));
				wPrev = map[i][j];
				wCnt = 1;
			}

			if (j <= N && map[j][i] == hPrev) ++hCnt;
			else if (j == N + 1 || map[j][i] != hPrev)
			{
				hV[i].emplace_back(Data(hPrev, hCnt));
				hPrev = map[j][i];
				hCnt = 1;
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		bool rs = true;
		for (int j = 1; j < wV[i].size(); ++j)
		{
			Data &prev = wV[i][j - 1];
			Data &now = wV[i][j];

			int gap = abs(now.first - prev.first);
			if (gap > 1) 
			{
				rs = false;
				break;
			}
			if (now.first > prev.first)
			{
				if (prev.second < L) { rs = false; break; }
			}
			else if (now.first < prev.first)
			{
				if (now.second < L) { rs = false; break; }
				else { now.second -= L; }
			}
		}
		if (rs) ++cnt;

		rs = true;
		for (int j = 1; j < hV[i].size(); ++j)
		{
			Data &prev = hV[i][j - 1];
			Data &now = hV[i][j];

			int gap = abs(now.first - prev.first);
			if (gap > 1)
			{
				rs = false;
				break;
			}
			if (now.first > prev.first)
			{
				if (prev.second < L) { rs = false; break; }
			}
			else if (now.first < prev.first)
			{
				if (now.second < L) { rs = false; break; }
				else { now.second -= L; }
			}
		}
		if (rs) ++cnt;
	}

	std::cout << cnt;

	return 0;
}
