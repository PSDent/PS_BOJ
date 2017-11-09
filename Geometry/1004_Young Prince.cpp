//================================================
// Filename : 1004_Young Prince
//
// Solved by PSDent.
// 
// https://www.acmicpc.net/problem/1004
//================================================

#include <iostream>
#include <cmath>

inline float Sqr(int x) {
	return x * x;
}

int Memo[50];
int sx, sy, ex, ey;
int cx, cy, r;

void CalPlanet(int index)
{
	float sDist = sqrt((Sqr(sx - cx) + Sqr(sy - cy)));
	float eDist = sqrt((Sqr(ex - cx) + Sqr(ey - cy)));

	if ((sDist > r) ^ (eDist > r))
		Memo[index]++;
}

int main()
{
	int T, N;

	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> sx >> sy >> ex >> ey >> N;

		for (int j = 0; j < N; j++)
		{
			std::cin >> cx >> cy >> r;
			CalPlanet(i);
		}
	}

	for (int i = 0; i < T; i++)
		std::cout << Memo[i] << std::endl;

	return 0;
}