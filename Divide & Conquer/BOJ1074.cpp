#include <iostream>
#include <cmath>

int R, C;

void Z(int n, int r,  int c)
{
	static bool check = false;
	static int cnt = 0;
	int term = pow(2, n - 1);
	int sR = r - pow(2, n) + 1, sC = c - pow(2, n) + 1;

	if (check) return;

	if ( (sR < R && R > r) || (sC < C && C > c))
	{
		cnt += (r - sR + 1) * (c - sC + 1);
		return;
	}

	if (n == 0 && r == R && c == C)
	{ 
		check = true;
		std::cout << cnt;
		return;
	}
	else if (n == 0)
	{
		++cnt;
		return;
	}

	Z(n - 1, r - term, c - term); // 좌상
	Z(n - 1, r - term, c); // 우상
	Z(n - 1, r, c - term); // 좌하
	Z(n - 1, r, c); // 우하
}

int main()
{
	int N;
	std::cin >> N >> R >> C;

	int start = (int)pow(2, N) - 1;
	Z(N, start, start);

	return 0;
}
