#include <iostream>
#include <string>

int main()
{
	std::string word1, word2;
	int min = 1000000;

	std::cin >> word1 >> word2;
	for (int i = 0; word2.size() - i >= word1.size(); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < word1.size(); ++j)
		{
			if (word2[i + j] != word1[j])
				++cnt;
		}
		if (cnt < min)
			min = cnt;
	}
	std::cout << min;
	return 0;
}
