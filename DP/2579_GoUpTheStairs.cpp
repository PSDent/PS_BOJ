//================================================
// Filename : 2579_GoUpTheStairs
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2579
//================================================
#include <iostream>

int maxVal = 0, N;
int stair[300];

void MaxStair(int index, int val)
{
	if(stair[index] + stair[index+1] > stair[index+2])


	return;
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> stair[i];

	MaxStair(0, 0);
	std::cout << maxVal;

	return 0;	
}
