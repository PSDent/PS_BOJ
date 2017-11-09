//================================================
// Filename : 2455_intelligent Train
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/2455
//================================================
#include <iostream>

int main()
{
	int max = 0, input = 0, save = 0;

	for (int i = 1; i <= 8; i++)
	{
		std::cin >> input;
		if (i % 2 == 1) save -= input;
		else save += input;

		if (save > max) max = save;
	}
	std::cout << max;
	return 0;
}