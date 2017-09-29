#include <iostream>

using namespace std;

typedef struct {
	int number;
	int gold;
	int silver;
	int bronze;
}MEDAL;

int main()
{
	MEDAL *nation = NULL;
	int N = 0, K = 0, count = 0;

	cin >> N >> K;

	nation = new MEDAL[N+1];

	for (int i = 1; i <= N; i++)
		cin >> nation[i].number >> nation[i].gold >> nation[i].silver >> nation[i].bronze;

	for (int i = 1; i <= N; i++)
	{
		if (i != K)
		{
			if (nation[i].gold > nation[K].gold)
				count++;
			else if (nation[i].gold == nation[K].gold)
			{
				if (nation[i].silver > nation[K].silver)
					count++;
				else if (nation[i].silver == nation[K].silver)
				{
					if (nation[i].bronze > nation[i].bronze)
						count++;
				}
			}

		}

	}

	delete[] nation;
	cout << count + 1;
}