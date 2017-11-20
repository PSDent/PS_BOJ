//================================================
// Filename : 10871_small_number_Than_X
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/10871
//================================================
#include <iostream>

int main()
{
	int A[10000] = { 0 };
	int N, X, index = 0;

	std::cin >> N >> X;

	int input;
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		if (input < X)
			A[index++] = input;
	}

	for (int i = 0; i < index; i++)
		std::cout << A[i] << ' ';

	return 0;
}
