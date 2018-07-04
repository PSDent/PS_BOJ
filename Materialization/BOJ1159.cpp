#include <iostream>
#include <string>

int alphabet[26];

int main()
{
	int N;
	std::string str, alphabetStr;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> str;
		++alphabet[str[0] - 97];
	}

	char ch = '0';
	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[i] >= 5)
		{
			ch = (char)(i + 97);
			std::cout << (char)(i + 97);
		}
	}

	if (ch == '0')
		std::cout << "PREDAJA";

	return 0;
}
