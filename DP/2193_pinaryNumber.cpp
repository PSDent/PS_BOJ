//================================================
// Filename : 2193_pinaryNumber
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2193
//================================================
#include <iostream>
#include <queue>

int N;
long long int d[90] = { 1 , 1, };

void PinaryNumber()
{
	for (int i = 2; i < N; i++)
		d[i] = d[i - 2] + d[i - 1];

	return;
}

int main()
{
	std::cin >> N;
	PinaryNumber();
	std::cout << d[N - 1];

	return 0;
}