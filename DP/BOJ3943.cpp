#include <iostream>
#include <algorithm>

int dp[100001];

int HailStone(int n)
{
	if (n == 1) return 1;
	else if (n <= 100000 && dp[n]) return dp[n];

	int nextN;
	if (n % 2 == 0) nextN = n / 2;
	else nextN = n * 3 + 1;

	int val;
	val = HailStone(nextN);
	if (n > val)
	{
		if(n <= 100000)
			dp[n] = n;
		val = n;
	}

	return val;
}

int main()
{
	int T, input;
	scanf("%d", &T);

	for (int i = 1; i <= 100000; ++i)
		dp[i] = HailStone(i);

	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &input);
		printf("%d\n", dp[input]);
	}

	return 0;
}
