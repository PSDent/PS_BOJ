#include <iostream>
#include <algorithm>

int num2(long long n)
{
	long long k = 1, cnt = 0;
	while (n >= (k *= 2))
		cnt += n / k;
	return cnt;
}

int num5(long long n)
{
	long long k = 1, cnt = 0;
	while (n >= (k *= 5))
		cnt += n / k;
	return cnt;
}

int main()
{
	long long n, m, a, b, c;
	std::cin >> n >> m;
	a = n; b = m; c = n - m;

	int bot_num2 = num2(b) + num2(c), bot_num5 = num5(b) + num5(c);
	int top_num2 = num2(a), top_num5 = num5(a);
	int total2 = top_num2 - bot_num2, total5 = top_num5 - bot_num5;
	int min = std::min(total2, total5);
	if (min > 0) std::cout << min;
	else std::cout << 0;

	return 0;
}
