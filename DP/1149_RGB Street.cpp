//================================================
// Filename : 1149_RGB Street
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1149
//================================================

#include <iostream>

typedef struct {
	int R, G, B;
}House;

House house[1000];
int minCost, N;

void CalCost(int cost, int num, int color)
{
	if (cost > minCost || num > N)
		return;

	if (N == num && cost < minCost)
	{
		minCost = cost;
		return;
	}
	else
	{
		switch (color) // 1 = R, 2 = G, 3 = B
		{
		case 1:
			CalCost(cost + house[num].G, num + 1, 2);
			CalCost(cost + house[num].B, num + 1, 3);
			break;
		case 2:
			CalCost(cost + house[num].R, num + 1, 1);
			CalCost(cost + house[num].B, num + 1, 3);
			break;
		case 3:
			CalCost(cost + house[num].R, num + 1, 1);
			CalCost(cost + house[num].G, num + 1, 2);
			break;
		default:
			CalCost(house[num].R, num + 1, 1);
			CalCost(house[num].G, num + 1, 2); 
			CalCost(house[num].B, num + 1, 3);
			break;
		}
	
	}
}

int main()
{	
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> house[i].R >> house[i].G >> house[i].B;
		minCost += house[i].R + house[i].G + house[i].B;
	}

	CalCost(0, 0, 0);

	std::cout << minCost;

	return 0;
}