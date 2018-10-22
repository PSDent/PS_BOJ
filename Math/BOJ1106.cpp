#include <iostream>
#include <string>
#include <cmath>

bool ban[10];

int main()
{
	std::string N;
	int M, input;
	int small = 1000000, big = 1000000;
	int smallSize, bigSize;

	std::cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> input;
		ban[input] = true;
	}

	std::string str;
	for (int i = std::stoi(N); i >= 0; --i)
	{
		str = std::to_string(i);
		int j = 0;
		for (j = 0; j < str.size(); ++j)
			if (ban[str[j] - '0']) break;
		if (j == str.size())
		{
			small = i;
			smallSize = str.size();
			break;
		}
	}

	for (int i = std::stoi(N); i <= 1000000; ++i)
	{
		str = std::to_string(i);
		int j = 0;
		for (j = 0; j < str.size(); ++j)
			if (ban[str[j] - '0']) break;
		if (j == str.size())
		{
			big = i;
			bigSize = str.size();
			break;
		}
	}

	small = abs(std::stoi(N) - small) + smallSize;
	big = abs(big - std::stoi(N)) + bigSize;

	int min = (small < big ? small : big);
	int updown = abs(std::stoi(N) - 100);

	std::cout << (min < updown ? min : updown);

	return 0;
}
