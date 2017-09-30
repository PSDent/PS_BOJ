//-----------------------------------------------
// Baekjoon_8979_Olympic 
//
// Problem URL : https://www.acmicpc.net/problem/8979
// 
// Coded by PSDent.
//
// GitHub : https://github.com/PSDent/algorithm
//------------------------------------------------

#include <iostream>

using namespace std;

typedef struct {
	int gold;
	int silver;
	int bronze;
}NATION;

int main()
{
	NATION *nation = NULL;
	int N = 0, K = 0, count = 0;

	cin >> N >> K;

	nation = new NATION[N+1];

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		cin >> temp;
		cin >> nation[temp].gold >> nation[temp].silver >> nation[temp].bronze;
	}

	for (int i = 1; i <= N; i++) {
		if (i == K)
			continue;

		if (nation[i].gold > nation[K].gold) count++;
		else if (nation[i].gold == nation[K].gold && nation[i].silver > nation[K].silver) count++;
		else if (nation[i].gold == nation[K].gold &&
			nation[i].silver == nation[K].silver && nation[i].bronze > nation[K].bronze) count++;
	}

	delete[] nation;
	cout << count + 1 << "\n";
}
