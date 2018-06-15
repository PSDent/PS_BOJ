#include <iostream>
#include <string>

int main(void) {
	std::string s;

	std::getline(std::cin, s);

	int cnt = 0;
	
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != ' ')
			++cnt;

		while (i < s.length())
		{
			if (s[i] == ' ')
				break;
			else
				++i;
		}
	}

	std::cout << cnt;

	return 0;
}