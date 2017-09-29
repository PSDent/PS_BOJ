#include <iostream>

using namespace std;

typedef struct {
	int number;
	int gold;
	int silver;
	int bronze;
}MEDAL;

bool operator==(const MEDAL& N1, const MEDAL& N2)
{
	if (N1.gold == N2.gold && N1.silver == N2.silver && N1.bronze == N2.bronze)
		return true;
	else
		return false;
}

int main()
{
	MEDAL *nation = NULL;
	int N = 0, K = 0, count = 0;

	cin >> N >> K;

	nation = new MEDAL[N+1];

	for (int i = 1; i <= N; i++)
		cin >> nation[i].number >> nation[i].gold >> nation[i].silver >> nation[i].bronze;

	for (int i = 1; i < N; i++)
	{
		if (nation[i] == nation[i + 1] && i != K)
			nation[i].number = -1;
		else if (nation[i] == nation[i + 1])
			nation[i + 1].number = -1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (i != K && nation[i].number != -1)
		{
			if (nation[i].gold > nation[K].gold)
				count++;
			else if (nation[i].gold == nation[K].gold)
			{
				if (nation[i].silver > nation[K].silver)
					count++;
				else if (nation[i].silver == nation[K].silver)
				{
					if (nation[i].bronze > nation[K].bronze)
						count++;
				}
			}

		}

	}

	delete[] nation;
	cout << count + 1;
}
