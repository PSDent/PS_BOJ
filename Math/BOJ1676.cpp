#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

const int MAX = 500;
bool num[MAX + 1];

int GetNum_2(int num)
{
	int cnt = 0;
	while (num % 2 == 0)
	{
		num /= 2;
		++cnt;
	}
	return cnt;
}

int GetNum_5(int num)
{
	int cnt = 0;
	while (num % 5 == 0)
	{
		num /= 5;
		++cnt;
	}
	return cnt;
}

int main()
{
	int N;
	std::cin >> N;

	int num2 = 0, num5 = 0;
	for (int i = 2; i <= N; ++i)
	{
		num2 += GetNum_2(i);
		num5 += GetNum_5(i);
	}

	std::cout << (num2 < num5 ? num2 : num5);

	return 0;
}
