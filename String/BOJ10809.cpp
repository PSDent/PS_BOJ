#include <iostream>
#include <string>

int pos[27];

int main()
{
	std::string str;
	std::cin >> str;

	for (int i = 0; i < 27; ++i) pos[i] = -1;
	for (int i = 0; i < str.size(); ++i)
	{
		if (pos[str[i] - 'a'] == -1)
			pos[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i) std::cout << pos[i] << ' ';

	return 0;
}
