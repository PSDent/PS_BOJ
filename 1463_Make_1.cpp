//================================================
// Filename : 1463_Make With 1 
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1463
//================================================
#include <iostream>

int minCnt = 100000;
int memo[1000000] = { 0 };

void MakeOne(int x, int cnt)
{
	if ( (memo[x] && cnt > memo[x]) || cnt > minCnt)
		return;

	if (x == 1 && cnt < minCnt)
	{
		minCnt = cnt;
		return;
	}

	else if(x != 1)
	{
		cnt++;
		if ( x % 3 == 0)
			MakeOne(x / 3, cnt);

		if ( x % 2 == 0)
			MakeOne(x / 2, cnt);

		MakeOne(x - 1, cnt);
	}
}

int main()
{
	int temp;

	std::cin >> temp;
	MakeOne(temp, 0);
	std::cout << minCnt;
	
	return 0;
}