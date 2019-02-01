#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string s, t;

	while (true)
	{
		std::cin >> s >> t;
		if (std::cin.eof())
			return 0;

		int index = 0;
		for (int i = 0; i < t.size(); ++i)
			if (s[index] == t[i])
			{
				++index;
				if (index == s.size())
				{
					std::cout << "Yes" << '\n';
					break;
				}
			}

		if (index != s.size())
			std::cout << "No" << '\n';
	}

	return 0;
}
