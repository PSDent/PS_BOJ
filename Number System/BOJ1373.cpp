#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string bin;
	std::cin >> bin;

	int lack = 3;
	if (bin.size() % 3 != 0)
	{
		lack = (bin.size() / 3 + 1) * 3 - bin.size();

		int sum = 0, exp = 4;
		int index = 0;

		for (; index < lack; ++index)
			exp /= 2;

		for (int i = 0; i < 3 - lack; ++i)
		{
			int val = bin[i] - '0';
			sum += val * exp;
			exp /= 2;
		}
		std::cout << sum;
	}

	for (int i = 3 - lack; i < bin.size(); i += 3)
	{
		int sum = 0;
		int one = bin[i] - '0';
		int two = bin[i + 1] - '0';
		int three = bin[i + 2] - '0';
		sum = one * 4 + two * 2 + three;
		std::cout << sum;
	}

	return 0;
}
