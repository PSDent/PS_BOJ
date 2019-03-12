#include <iostream>
#include <string>

int main()
{
	std::string str;
	
	while (std::getline(std::cin, str))
	{
		int lower = 0, upper = 0, num = 0, empty = 0;

		if (!std::cin) break;

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z') ++lower;
			else if (str[i] >= 'A' && str[i] <= 'Z') ++upper;
			else if (str[i] >= '0' && str[i] <= '9') ++num;
			else ++empty;
		}
		std::cout << lower << ' ' << upper << ' ' << num << ' ' << empty << '\n';
	}


	return 0;
}
