#include <iostream>
#include <string>

int num[10];

int main()
{
	int cnt96 = 0, total = 0, max = 0;
	std::string N;

	std::cin >> N;

	for (int i = 0; i < N.size(); ++i)
	{
		if (N[i] == '6' || N[i] == '9')
			++cnt96;
		else
			++num[N[i] - 48];
	}

	for (int i = 0; i < 10; ++i)
		if (num[i] > max)
			max = num[i];

	if ((cnt96 / 2) + cnt96 % 2 > max)
		total = (cnt96 / 2) + cnt96 % 2;
	else
		total = max;

	std::cout << total;

	return 0;
}
