#include <iostream>
#include <string>
#include <cmath>
#include <queue>

struct Wheel
{
	int index, l, r;
	Wheel(int a, int b, int c) : index(a), l(b), r(c) {};
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int k;
	int side[4][2] = { {2, 6}, {2, 6}, {2, 6}, {2, 6} };
	std::string wheel[4];

	for (int i = 0; i < 4; ++i)
		std::cin >> wheel[i];
	std::cin >> k;

	std::queue<Wheel> q;
	int no, dir;
	for (int i = 0; i < k; ++i) // 1 -> 시계  / -1 반시계
	{
		std::cin >> no >> dir;
		no -= 1;

		int localDir = -dir;
		for (int j = no - 1; j >= 0; --j) // 왼쪽
		{
			localDir = -localDir;
			int lRS = side[j][0], rLS = side[j + 1][1];
			if (wheel[j][lRS] == wheel[j + 1][rLS]) break;
			q.emplace(j, (localDir + side[j][0] + 8) % 8, (localDir + side[j][1] + 8) % 8);
		}

		while (!q.empty())
		{
			Wheel top = q.front(); q.pop();
			side[top.index][0] = top.l;
			side[top.index][1] = top.r;
		}
		q = std::queue<Wheel>();

		localDir = -dir;
		for (int j = no + 1; j < 4; ++j) // 오른쪽
		{
			localDir = -localDir;
			int lRS = side[j - 1][0], rLS = side[j][1];
			if (wheel[j - 1][lRS] == wheel[j][rLS]) break;
			q.emplace(j, (localDir + side[j][0] + 8) % 8, (localDir + side[j][1] + 8) % 8);
		}

		while (!q.empty())
		{
			Wheel top = q.front(); q.pop();
			side[top.index][0] = top.l;
			side[top.index][1] = top.r;
		}
		q = std::queue<Wheel>();
		side[no][0] = (-dir + side[no][0] + 8) % 8;
		side[no][1] = (-dir + side[no][1] + 8) % 8;
	}

	int point = 0;
	for (int i = 0; i < 4; ++i)
	{
		int temp = wheel[i][(side[i][0] - 2 + 8) % 8] - '0';
		point += temp * (int)pow(2, i);
	}

	std::cout << point;
	return 0;
}
