//================================================
// Filename : 5585_Change
//
// Solved by PSDent.
// 
// https://www.acmicpc.net/problem/5585
//================================================
#include <iostream>

#define MONEY 1000
int ChangeList[6] = { 500, 100, 50, 10, 5, 1 };
int cnt = 0;

void Greedy(int pay)
{
	int change = MONEY - pay;

		for (int i = 0; i < 6; i++){
			if (!change)
				return;
			cnt += change / ChangeList[i];
			change = change - (change / ChangeList[i] * ChangeList[i]);
		}

	return;
}

int main()
{
	int pay;

	std::cin >> pay;
	Greedy(pay);
	std::cout << cnt;

	return 0;
}
