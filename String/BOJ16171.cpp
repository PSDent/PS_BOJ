#include <iostream>
#include <string>

int main()
{
	std::string word1, word2;
	std::cin >> word1 >> word2;

	for (int i = 0; i < word1.size(); ++i)
		if (word1[i] >= '0' && word1[i] <= '9')
			word1.erase(i--, 1);

	for (int i = 0; i + word2.size() <= word1.size(); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < word2.size(); ++j)
		{
			if (word1[i + j] == word2[j])
				++cnt;
			else
				break;
		}
		if (cnt == word2.size())
		{
			std::cout << 1;
			return 0;
		}
	}

	std::cout << 0;
	return 0;
}
