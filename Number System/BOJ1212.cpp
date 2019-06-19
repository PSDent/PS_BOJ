#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	bool isFirst = true;
	std::string str;
	std::cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		int binary[3];

		int num = str[i] - '0';
		binary[0] = num / 4;
		binary[1] = (num % 4) / 2;
		binary[2] = (num % 4 % 2);

		if (isFirst)
		{
			isFirst = false;
			int index = 0;
			for (; index < 3; ++index)
			{
				if (binary[index] == 0)
					continue;
				else
					break;
			}

			if (index == 3)
			{
				std::cout << 0; 
				return 0;
			}

			for (; index < 3; ++index)
				std::cout << binary[index];
		}
		else
			std::cout << binary[0] << binary[1] << binary[2];
	}

	return 0;
}