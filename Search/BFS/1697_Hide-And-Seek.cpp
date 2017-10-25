//================================================
// Filename : 1697_Hide-And-Seek
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/1697
//================================================
#include <iostream>
#include <queue>

int check[100001] = { 0 };
int K;

void BFS(int x)
{
	std::queue<int> q;
	int temp;

	q.push(x);
	while (q.front() != K)
	{
		temp = q.front();
		q.pop();

		std::cout << temp << '\n';
		if (temp - 1 >= 0 && !check[temp - 1])
		{
			check[temp - 1] = check[temp] + 1;
			q.push(temp - 1);
		}

		if (temp + 1 <= 100000 && !check[temp + 1])
		{
			check[temp + 1] = check[temp] + 1;
			q.push(temp + 1);
		}

		if (temp * 2 <= 100000 && !check[temp * 2])
		{
			check[temp * 2] = check[temp] + 1;
			q.push(temp * 2);
		}
	}

}

int main()
{
	int N;
	std::cin >> N >> K;

	BFS(N);
	std::cout << check[K];

	return 0;
}