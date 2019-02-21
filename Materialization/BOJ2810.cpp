#include <iostream>
#include <string>

int main()
{
	int N, sn = 0, ln = 0;
	std::string str;
	std::cin >> N >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'S') ++sn;
		else
		{
			++ln; i += 1;
		}
	}

	if (ln)	std::cout << sn + ln + 1;
	else std::cout << sn;
	return 0;
}
