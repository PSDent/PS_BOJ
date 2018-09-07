#include <iostream>

int N;
bool step = false;
int dp1[2][3], dp2[2][3];
int a, b, c;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b >> c;
		
		dp1[step][0] = a + Max(dp1[!step][0], dp1[!step][1]);
		dp1[step][1] = b + Max(dp1[!step][0], Max(dp1[!step][1], dp1[!step][2]));
		dp1[step][2] = c + Max(dp1[!step][1], dp1[!step][2]);

		dp2[step][0] = a + Min(dp2[!step][0], dp2[!step][1]);
		dp2[step][1] = b + Min(dp2[!step][0], Min(dp2[!step][1], dp2[!step][2]));
		dp2[step][2] = c + Min(dp2[!step][1], dp2[!step][2]);
		step = !step;
	}

	step = !step;
	std::cout << Max(dp1[step][0], Max(dp1[step][1], dp1[step][2])) << ' ';
	std::cout << Min(dp2[step][0], Min(dp2[step][1], dp2[step][2]));

	return 0;
}
