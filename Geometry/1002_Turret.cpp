//================================================
// Filename : 1002_Turret
//
// Solved by PSDent.
// 
// https://www.acmicpc.net/problem/1002
//================================================

#include <iostream>
#include <cmath>

typedef struct {
	int x, y, r;
}Coord;

int *num = NULL;
Coord turret[2];

inline int sqr(int x)
{
	return x * x;
}

void CalPoint(int index, short bigger)
{
	double dist = sqrt( (double)sqr(turret[0].x - turret[1].x) + (double)sqr(turret[0].y - turret[1].y) );

	if (turret[0].x == turret[1].x && turret[0].y == turret[1].y && bigger == 2) // 원이 같음.
		num[index] = -1;

	else if (turret[bigger].r > dist) // 내접 
	{
		if (dist + turret[!bigger].r < turret[bigger].r)
			num[index] = 0;
		else if (dist + turret[!bigger].r > turret[bigger].r)
			num[index] = 2;
		else
			num[index] = 1;
	}
	else
	{
		if (turret[0].r + turret[1].r == dist)
			num[index] = 1;
		else if (turret[0].r + turret[1].r < dist)
			num[index] = 0;
		else if (turret[0].r + turret[1].r > dist)
			num[index] = 2;
	}

	return;
}

int main()
{
	int T;

	std::cin >> T;
	num = new int[T];

	for (int i = 0; i < T; i++)
	{
		std::cin >> turret[0].x >> turret[0].y >> turret[0].r >> turret[1].x >> turret[1].y >> turret[1].r;
		if (turret[0].r > turret[1].r)
			CalPoint(i, 0);
		else if (turret[1].r > turret[0].r)
			CalPoint(i, 1);
		else
			CalPoint(i, 2);
	}

	for (int i = 0; i < T; i++)
		std::cout << num[i] << '\n';


	delete[] num;
	return 0;
}