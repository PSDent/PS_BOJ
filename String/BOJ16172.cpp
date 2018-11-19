#include <iostream>
#include <string>

int main()
{
	std::string word1, word2;
	std::cin >> word1 >> word2;

	for (int i = 0; i < word1.size(); ++i)
		if (word1[i] >= '0' && word1[i] <= '9')
			word1.erase(i--, 1);

	int a = word1.find(word2);
	if (a != std::string::npos)
		std::cout << 1;
	else
		std::cout << 0;
	return 0;
}
