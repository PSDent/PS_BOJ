#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::string str;
	std::getline(std::cin, str);

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
			std::cout << str[i];
		else
		{
			char add;
			int val;
			if (str[i] >= 'a' && str[i] <= 'z')
				val = str[i] - 'a', add = 'a';
			else
				val = str[i] - 'A', add = 'A';
		
			val = (val + 13) % 26;
			std::cout << (char)(val + add);
		}

	}

	return 0;
}
