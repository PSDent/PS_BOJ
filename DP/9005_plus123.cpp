//================================================
// Filename : 9005_plus 1,2,3
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/9095
//================================================
#include <iostream>	

short N, DP[251001], arr[251001], max;
long long int a;
void Bigger(short a) {
	max = max < a ? a : max;
	return;
}

void Calculate()
{
	int index = 0;
	DP[0] = arr[0];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[index + i ] + DP[index] > DP[index + i])
				DP[index + i ] = arr[index + i ] + DP[index];

			if (arr[index + i  + 1] + DP[index] > DP[index + i  + 1])
				DP[index + i  + 1] = arr[index + i  + 1] + DP[index];
			index++;
		}
	}

	return;
}

int main()
{
	int t = 0;

	std::cin >> N;
	for (int i = 1; i <= N; i++) t += i;
	for (int i = 0; i < t; i++) std::cin >> arr[i];
	Calculate();

	for (int i = t - N - 1; i < t; i++)
		Bigger(DP[i]);

	std::cout << max;
	return 0;
}