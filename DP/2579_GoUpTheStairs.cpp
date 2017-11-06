//================================================
// Filename : 2579_GoUpTheStairs
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2579
//================================================
#include <iostream>

int Bigger(int A, int B) {
	return A > B ? A : B;
}

int main()
{
	int maxVal = 0, N;
	int stair[300], DP[300];

	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> stair[i];

	DP[0] = stair[0];
	DP[1] = stair[0] + stair[1];
	DP[2] = Bigger(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < N; i++)
	{
		DP[i] = Bigger(DP[i - 3] + stair[i - 1] + stair[i], DP[i - 2] + stair[i]);
	}

	std::cout << DP[N - 1];

	return 0;
}
