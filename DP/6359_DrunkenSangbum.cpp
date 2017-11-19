//================================================
// Filename : 6359_DrunkenSangbum.cpp
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/6359
//================================================
#include <iostream>

bool room[101] = { false };
int t, n, popul[10000];

void Check(int index)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (i > 1)
			{
				if (room[j])
					room[j] = false;
				else
					room[j] = true;
			}
			else
				room[j] = true;
		}
	}

	for (int i = 1; i <= n; i++)
		if (room[i])
			popul[index]++;

	return;
}

int main()
{
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		Check(i);
	}

	for (int j = 0; j < t; j++)
		std::cout << popul[j] << std::endl;

	return 0;
}
