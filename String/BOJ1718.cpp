#include <iostream>
#include <string>

int main()
{
	std::string clear, password;
	std::getline(std::cin, clear);
	std::getline(std::cin, password);

	for (int i = 0; i < clear.size(); ++i)
	{
		if (clear[i] == ' ')
		{
			std::cout << ' '; continue;
		}

		int index = i % password.size();
		int offset = password[index] - 'a' + 1;
		int val = (clear[i] - 'a' - offset + 26) % 26;
		std::cout << (char)(val + 'a');
	}


	return 0;
}
